/****************************************************************************
*                                                                           *
*  OpenNI 1.x Alpha                                                         *
*  Copyright (C) 2011 PrimeSense Ltd.                                       *
*                                                                           *
*  This file is part of OpenNI.                                             *
    *
*                                                                           *
****************************************************************************/
//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "NiHandTracker.h"
#include <cassert>


using namespace xn;
typedef TrailHistory::Trail Trail;


//---------------------------------------------------------------------------
// Defines
//---------------------------------------------------------------------------
#define LENGTHOF(arr)			(sizeof(arr)/sizeof(arr[0]))
#define FOR_ALL(arr, action)	{for(int i = 0; i < LENGTHOF(arr); ++i){action(arr[i])}}

#define ADD_GESTURE(name)		{if(m_GestureGenerator.AddGesture(name, NULL) != XN_STATUS_OK){printf("Unable to add gesture"); exit(1);}}
#define REMOVE_GESTURE(name)	{if(m_GestureGenerator.RemoveGesture(name) != XN_STATUS_OK){printf("Unable to remove gesture"); exit(1);}}

#define ADD_ALL_GESTURES		FOR_ALL(cGestures, ADD_GESTURE)
#define REMOVE_ALL_GESTURES		FOR_ALL(cGestures, REMOVE_GESTURE)


//---------------------------------------------------------------------------
// Consts
//---------------------------------------------------------------------------
// Gestures to track
static const char			cClickStr[] = "Click";
static const char			cWaveStr[] = "Wave";
static const char* const	cGestures[] =
{
	cClickStr,
	cWaveStr
};

//---------------------------------------------------------------------------
// Statics
//---------------------------------------------------------------------------
XnList	HandTracker::sm_Instances;


//---------------------------------------------------------------------------
// Hooks
//---------------------------------------------------------------------------
void XN_CALLBACK_TYPE HandTracker::Gesture_Recognized(	xn::GestureGenerator&	generator, 
														const XnChar*			strGesture, 
														const XnPoint3D*		pIDPosition, 
														const XnPoint3D*		pEndPosition, 
														void*					pCookie)
{
	printf("Gesture recognized: %s\n", strGesture);

	HandTracker*	pThis = static_cast<HandTracker*>(pCookie);
	if(sm_Instances.Find(pThis) == sm_Instances.end())
	{
		printf("Dead HandTracker: skipped!\n");
		return;
	}

	pThis->m_HandsGenerator.StartTracking(*pEndPosition);
}

void XN_CALLBACK_TYPE HandTracker::Hand_Create(	xn::HandsGenerator& generator, 
												XnUserID			nId, 
												const XnPoint3D*	pPosition, 
												XnFloat				fTime, 
												void*				pCookie)
{
	printf("New Hand: %d @ (%f,%f,%f)\n", nId, pPosition->X, pPosition->Y, pPosition->Z);

	HandTracker*	pThis = static_cast<HandTracker*>(pCookie);
	if(sm_Instances.Find(pThis) == sm_Instances.end())
	{
		printf("Dead HandTracker: skipped!\n");
		return;
	}

	// Add to hands history if this user is not already tracked
	if(!pThis->m_History.Find(nId))
	{
		pThis->m_History.Add(nId).Push(*pPosition);
		if(pThis->m_sync){
			pThis->m_sync->HandCreate(nId,pPosition);
			MessageBox(NULL,L"seesee",L"see",MB_OK);
		}
		//WCHAR t10[10];
		//MessageBox(NULL,_itow(nId,t10,10),L"Find",MB_OK);
	}
}

void XN_CALLBACK_TYPE HandTracker::Hand_Update(	xn::HandsGenerator& generator, 
												XnUserID			nId, 
												const XnPoint3D*	pPosition, 
												XnFloat				fTime, 
												void*				pCookie)
{
	HandTracker*	pThis = static_cast<HandTracker*>(pCookie);
	if(sm_Instances.Find(pThis) == sm_Instances.end())
	{
		printf("Dead HandTracker: skipped!\n");
		return;
	}
	// Add to this user's hands history
	Trail*	const trail = pThis->m_History.Find(nId);
	if(!trail)
	{
		printf("Dead hand update: skipped!\n");
		return;
	}
	trail->Push(*pPosition);
	if (pThis->m_sync)
	{
		pThis->m_sync->HandUpdate(nId,pPosition);
	}
}

void XN_CALLBACK_TYPE HandTracker::Hand_Destroy(	xn::HandsGenerator& generator, 
													XnUserID			nId, 
													XnFloat				fTime, 
													void*				pCookie)
{
	printf("Lost Hand: %d\n", nId);

	HandTracker*	pThis = static_cast<HandTracker*>(pCookie);
	if(sm_Instances.Find(pThis) == sm_Instances.end())
	{
		printf("Dead HandTracker: skipped!\n");
		return;
	}

	// Remove this user from hands history
	pThis->m_History.Remove(nId);
}


//---------------------------------------------------------------------------
// Method Definitions
//---------------------------------------------------------------------------
HandTracker::HandTracker(xn::Context& context)
:m_rContext(context),
m_History(MAX_HAND_TRAIL_LENGTH)
{
	// Track all living instances (to protect against calling dead pointers in the Gesture/Hand Generator hooks)
	XnStatus rc = sm_Instances.AddLast(this);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to add NiHandTracker instance to the list.");
		exit(1);
	}
}

HandTracker::~HandTracker()
{
	// Remove the current instance from living instances list
	XnList::ConstIterator it = sm_Instances.Find(this);
	assert(it != sm_Instances.end());
	sm_Instances.Remove(it);
}

XnStatus HandTracker::Init(HandSYNC* sync)
{            
	XnStatus			rc;
	XnCallbackHandle	chandle;
	m_sync=sync;
	// Create generators
	rc = m_GestureGenerator.Create(m_rContext);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to create GestureGenerator.");
		return rc;
	}

	rc = m_HandsGenerator.Create(m_rContext);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to create HandsGenerator.");
		return rc;
	}

	// Register callbacks
	// Using this as cookie
	rc = m_GestureGenerator.RegisterGestureCallbacks(Gesture_Recognized, Gesture_Process, this, chandle);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to register gesture callbacks.");
		return rc;
	}

	rc = m_HandsGenerator.RegisterHandCallbacks(Hand_Create, Hand_Update, Hand_Destroy, this, chandle);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to register hand callbacks.");
		return rc;
	}

	return XN_STATUS_OK;
}

XnStatus HandTracker::Run()
{
	//ADD_ALL_GESTURES;
	XnStatus	rc = m_rContext.StartGeneratingAll();
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to start generating.");
		return rc;
	}

	ADD_ALL_GESTURES;

	return XN_STATUS_OK;
}

