#include "stdafx.h"
#include "ControlKinect.h"
#include "NiHandTracker.h"
#include "NiUserDetector.h"
#include "Temp4Debug.h"
//using namespace xn;
//xn::UserGenerator usrGen;
xn::Context g_context;
//HandTracker* ht;
NiUserDetector* ud;
XnStatus Init_Kinect(){
	XnStatus rc;
	#ifdef _DEBUG
		rc=g_context.Init();
		CHECK_RC(rc,"get g_context fail");
		xn::DepthGenerator depGen;
		rc=depGen.Create(g_context);
		CHECK_RC(rc,"get depGen fail");
		xn::ImageGenerator imgGen;
		rc=imgGen.Create(g_context);
		CHECK_RC(rc,"get imgGen fail");
		/*UserGenerator usrGen;
		rc=usrGen.Create(g_context);
		CHECK_RC(rc,"get UsrGen fail");
		SceneAnalyzer scnAnly;
		rc=scnAnly.Create(g_context);
		CHECK_RC(rc,"get ScnAnly fail");	*/
    #else
		rc=g_context.InitFromXmlFile(SAMPLE_XML_PATH,NULL);
		CHECK_RC(rc,"get g_context fail");
	#endif // _DEBUG
	
	/*	rc=g_context.StartGeneratingAll();
		CHECK_RC(rc,"start all fail");
		ht =new HandTracker(g_context);
		rc=ht->Init();
		ht->Run();
		rc=usrGen.Create(g_context);
		const XnChar* nm=usrGen.GetName();
		WCHAR tnm[20];
		memset(tnm,0,20);
		swprintf_s(tnm,20,L"name:%s",nm);
	//	const WCHAR* nm =_T(usrGen.GetName());
		if(rc==XN_STATUS_OK){
			MessageBox(NULL,tnm,L"title",MB_OK);
			MessageBeep(16);
		}*/
		ud=new NiUserDetector(g_context);
		rc=ud->Init();
		if(rc==XN_STATUS_OK){
			MessageBox(NULL,L"fudu",L"title",MB_OK);
			MessageBeep(16);
		}
		ud->Run();
	return rc;
}

XnStatus updateKinect(){
	XnStatus rc=g_context.WaitAndUpdateAll();
	XnUInt16 cnt=20;
	XnUserID uid[20];
	XnUserSkeleton tmp;
	ud->getAllUser(uid,cnt);
		for(int i=0;i<cnt;i++){
			ud->getAllJoint(uid[i],tmp);
			for(int j=1;j<=24;j++){
				XnSkeletonJointTransformation trans;
				tmp.Get((XnSkeletonJoint)j,trans);
				wrt_i(trans.position.position.X);
				wrt_Wchr(L"\r\n");
				wrt_i(trans.position.position.Y);
			}
			
		}

	return 	rc;
}

