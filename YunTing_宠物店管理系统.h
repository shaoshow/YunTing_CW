
// YunTing_宠物店管理系统.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CYunTing宠物店管理系统App:
// 有关此类的实现，请参阅 YunTing_宠物店管理系统.cpp
//

class CYunTing宠物店管理系统App : public CWinApp
{
public:
	CYunTing宠物店管理系统App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CYunTing宠物店管理系统App theApp;
