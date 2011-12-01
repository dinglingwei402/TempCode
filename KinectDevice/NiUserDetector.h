#include <XnCppWrapper.h>
class NiUserDetector{
	
public:	
	NiUserDetector(xn::Context& context);
	~NiUserDetector();
	XnStatus Init();
	XnStatus Run();
	void Stop();
	XnUserID getPlayer();
private:
	static void XN_CALLBACK_TYPE UserExit(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE UserReEnter(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE NewUser(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE LostUser(xn::UserGenerator &generator, XnUserID user, void *pCookie);
	static void XN_CALLBACK_TYPE UserCalibrationComplete(xn::SkeletonCapability& capability, XnUserID nId, XnCalibrationStatus eStatus, void* pCookie);
	
	xn::Context g_context;
	xn::UserGenerator g_usrGen;
	XnCallbackHandle hUserExit,hUserReEnter,hUserCallbacks,hCalibration;
	static XnUserID playerId;
};