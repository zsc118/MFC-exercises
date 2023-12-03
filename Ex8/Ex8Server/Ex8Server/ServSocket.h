#pragma once
#include "afxsock.h"
class CEx8ServerDlg;
class CServSocket :
	public CSocket
{
public:
	CServSocket();
	~CServSocket();
	CServSocket(CEx8ServerDlg *Dlg);
	CEx8ServerDlg* m_Dlg;
	virtual void OnAccept(int nErrorCode);
};

