#include "stdafx.h"
#include "ClientSocket.h"

#include "Ex8ClientDlg.h"

CClientSocket::CClientSocket()
{
}


CClientSocket::~CClientSocket()
{
}


CClientSocket::CClientSocket(CEx8ClientDlg* Dlg)
{
	m_Dlg = Dlg;
}

void CClientSocket::OnReceive(int nErrorCode)
{
	CString str;
	m_Dlg->m_LogCtrl.AddString(TEXT("对方发来消息如下:"));
	*m_ArIn >> str;
	m_Dlg->m_LogCtrl.AddString(str);
	m_Dlg->m_LogCtrl.SetCurSel(m_Dlg->m_LogCtrl.GetCount() - 1);

	CSocket::OnReceive(nErrorCode);
}
