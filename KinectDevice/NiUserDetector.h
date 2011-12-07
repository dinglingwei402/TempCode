#include <XnCppWrapper.h>
#include <XnHash.h>
#include <XnList.h>
#include "UserSYNC.h"

XN_DECLARE_DEFAULT_HASH(XnSkeletonJoint,XnSkeletonJointTransformation,XnUserSkeleton);
XN_DECLARE_DEFAULT_HASH(XnUserID,XnUserSkeleton,XnUserSkeletonSet);

class UserTracker{	
public:	
	UserTracker(xn::Context& context);
	~UserTracker();
	XnStatus Init(UserSYNC* sync);
	XnStatus Run();
	void Stop();
	XnUserID getPlayer();
	void Update();
private:
	static void XN_CALLBACK_TYPE UserExit(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE UserReEnter(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE NewUser(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE LostUser(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE poseDetected(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE UserCalibrationComplete(xn::SkeletonCapability& capability, XnUserID nId, XnCalibrationStatus eStatus, void* pCookie);
	static void XN_CALLBACK_TYPE UserPositionChanged(xn::ProductionNode &node,void* pCookie);
	xn::Context g_context;
	xn::UserGenerator g_usrGen;
	xn::DepthGenerator g_depGen;
	XnCallbackHandle hUserExit,hUserReEnter,hUserCallbacks,hCalibration,hUserPostionChanged;
	XnUserID playerId;
	UserSYNC* m_sync;
	static XnList sm_Instances;
};

