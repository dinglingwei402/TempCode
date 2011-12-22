#include "globalVar.h"
#include "XnOpenNI.h"
#ifdef  KDDLL_API
#else 
#define KDDLL_API _declspec(dllimport)
#endif
 KDDLL_API  void  init();
 KDDLL_API  GenGrp getGrp();
 KDDLL_API bool CheckUser(int devID,int UserID);
 KDDLL_API void drawPoint();

