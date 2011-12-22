========================================================================
    活动模板库 : KinectDevice 项目概述
========================================================================

应用程序向导已为您创建了此 KinectDevice 项目，作为编写动态链接库 (DLL) 的起点。

本文件概要介绍组成项目的每个文件的内容。

KinectDevice.vcproj
    这是使用应用程序向导生成的 VC++ 项目的主项目文件，
    其中包含生成该文件的 Visual C++ 的版本信息，以及有关使用应用程序向导选择的平台、配置和项目功能的信息。

KinectDevice.idl
    此文件包含项目中定义的类型库、接口和 co-class 的 IDL 定义。
    此文件将由 MIDL 编译器进行处理以生成：
        C++ 接口定义和 GUID 声明 (KinectDevice.h)
        GUID 定义                                (KinectDevice_i.c)
        类型库                                  (KinectDevice.tlb)
        封送处理代码                                 （KinectDevice_p.c 和 dlldata.c）

KinectDevice.h
    此文件包含 KinectDevice.idl 中定义的项目的 C++ 接口定义和 GUID 声明。它将在编译过程中由 MIDL 重新生成。

KinectDevice.cpp
    此文件包含对象映射和 DLL 导出的实现。

KinectDevice.rc
    这是程序使用的所有 Microsoft Windows 资源的列表。

KinectDevice.def
    此模块定义文件为链接器提供有关 DLL 所要求的导出的信息，其中包含用于以下内容的导出：
DllGetClassObject
DllCanUnloadNow
DllRegisterServer
DllUnregisterServer

/////////////////////////////////////////////////////////////////////////////
其他标准文件：

StdAfx.h, StdAfx.cpp
    这些文件用于生成名为 KinectDevice.pch 的预编译头 (PCH) 文件和名为 StdAfx.obj 的预编译类型文件。

Resource.h
    这是用于定义资源 ID 的标准头文件。

/////////////////////////////////////////////////////////////////////////////
代理/存根 (stub) DLL 项目和模块定义文件：

KinectDeviceps.vcproj
    此文件是用于生成代理/存根 (stub) DLL 的项目文件（若有必要）。
	主项目中的 IDL 文件必须至少包含一个接口，并且
	在生成代理/存根 (stub) DLL 之前必须先编译 IDL 文件。	此进程生成
	dlldata.c、KinectDevice_i.c 和 KinectDevice_p.c，这些文件是
	生成代理/存根 (stub) DLL 所必需的。

KinectDeviceps.def
    此模块定义文件为链接器提供有关代理/存根 (stub) 所要求的导出的信息。

/////////////////////////////////////////////////////////////////////////////