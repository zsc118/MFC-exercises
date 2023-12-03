#include "stdafx.h"
#include "RecvSocket.h"

#include "Ex8ServerDlg.h"

CRecvSocket::CRecvSocket()
{
}


CRecvSocket::~CRecvSocket()
{
}


CRecvSocket::CRecvSocket(CEx8ServerDlg* Dlg)
{
	m_Dlg = Dlg;
}

void CRecvSocket::OnReceive(int nErrorCode)
{
	CString str;
	(*m_ArIn) >> str;
	m_Dlg->m_LogCtrl.AddString(TEXT("对方发来的信息如下:"));
	m_Dlg->m_LogCtrl.AddString(str);
	m_Dlg->m_LogCtrl.SetCurSel(m_Dlg->m_LogCtrl.GetCount() - 1);

	CSocket::OnReceive(nErrorCode);
}
