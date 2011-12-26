// dllmain.h : 模块类的声明。

class CScanPersonModule : public CAtlDllModuleT< CScanPersonModule >
{
public :
	DECLARE_LIBID(LIBID_ScanPersonLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SCANPERSON, "{EA656A58-08A7-41E0-9E97-FE79832158DF}")
};

extern class CScanPersonModule _AtlModule;
