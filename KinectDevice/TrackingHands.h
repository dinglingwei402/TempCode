#include <map>
#include <list>
#include <XnCppWrapper.h>
#include <XnVPointControl.h>

#include "NiTrailHistory.h"


typedef enum
{
	IN_SESSION,
	NOT_IN_SESSION,
	QUICK_REFOCUS
} SessionState;
class XnVPointDrawer : public XnVPointControl
{
public:
	XnVPointDrawer(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator);
	virtual ~XnVPointDrawer();

	/**
	 * Handle a new message.
	 * Calls other callbacks for each point, then draw the depth map (if needed) and the points
	 */
	void Update(XnVMessage* pMessage);

	/**
	 * Handle creation of a new point
	 */
	void OnPointCreate(const XnVHandPointContext* cxt);
	/**
	 * Handle new position of an existing point
	 */
	void OnPointUpdate(const XnVHandPointContext* cxt);
	/**
	 * Handle destruction of an existing point
	 */
	void OnPointDestroy(XnUInt32 nID);

	/**
	 * Draw the points, each with its own color.
	 */
	void Draw() const;

	/**
	 * Change mode - should draw the depth map?
	 */
	void SetDepthMap(XnBool bDrawDM);
	/**
	 * Change mode - print out the frame id
	 */
	void SetFrameID(XnBool bFrameID);

	void SetTouchingFOVEdge(XnUInt32 nID);

	XnBool IsTouching(XnUInt32 nID) const;
	// Number of previous position to store for each hand
	XnUInt32 m_nHistorySize;
	// previous positions per hand
	std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	std::list<XnUInt32> m_TouchingFOVEdge;
	// Source of the depth map
	xn::DepthGenerator m_DepthGenerator;
	XnFloat* m_pfPositionBuffer_1;
	XnFloat* m_pfPositionBuffer_2;
	XnUInt32 m_handCnt;
	XnBool m_bDrawDM;
	XnBool m_bFrameID;
	XnUInt32 m_handID;
};

SessionState GetSessionStatus();
XnUInt32 GetBufferSize();
XnUInt32 GetHandCnt();
VOID updateHands();
XnStatus init_hands();
XnStatus GetHandTrackPoint(int i,float** vec);
XnUserID GetHandID();
SessionState GetSessionStatus();