#pragma once
#include "afxsock.h"
class CEx8ClientDlg;
class CClientSocket :
	public CSocket
{
public:
	CClientSocket();
	~CClientSocket();
	CClientSocket(CEx8ClientDlg* Dlg);
	CEx8ClientDlg* m_Dlg;
	CSocketFile *m_File;
	CArchive *m_ArIn;
	CArchive *m_ArOut;
	virtual void OnReceive(int nErrorCode);
};

