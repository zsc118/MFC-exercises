#pragma once
#include "afxsock.h"
class CEx8ServerDlg;
class CRecvSocket :
	public CSocket
{
public:
	CRecvSocket();
	~CRecvSocket();
	CRecvSocket(CEx8ServerDlg* Dlg);
	CEx8ServerDlg* m_Dlg;
	CSocketFile *m_File;
	CArchive *m_ArIn;
	CArchive *m_ArOut;
	virtual void OnReceive(int nErrorCode);
};

