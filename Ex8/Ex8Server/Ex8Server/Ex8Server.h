
// Ex8Server.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEx8ServerApp: 
// �йش����ʵ�֣������ Ex8Server.cpp
//

class CEx8ServerApp : public CWinApp
{
public:
	CEx8ServerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEx8ServerApp theApp;