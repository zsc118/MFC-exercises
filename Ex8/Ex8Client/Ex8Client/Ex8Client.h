
// Ex8Client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEx8ClientApp: 
// �йش����ʵ�֣������ Ex8Client.cpp
//

class CEx8ClientApp : public CWinApp
{
public:
	CEx8ClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEx8ClientApp theApp;