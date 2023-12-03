#include "stdafx.h"
#include "ServSocket.h"

#include "Ex8ServerDlg.h"
#include "RecvSocket.h"

CServSocket::CServSocket()
{
}


CServSocket::~CServSocket()
{
}


CServSocket::CServSocket(CEx8ServerDlg* Dlg)
{
	m_Dlg = Dlg;
}

void CServSocket::OnAccept(int nErrorCode)
{
	CRecvSocket *tempSock;
	if (tempSock = new CRecvSocket(this->m_Dlg))
		if (Accept(*tempSock))
		{
			tempSock->m_File = new CSocketFile(tempSock);
			tempSock->m_ArIn = new CArchive(tempSock->m_File, CArchive::load);
			tempSock->m_ArOut = new CArchive(tempSock->m_File, CArchive::store);
			m_Dlg->RecvSock = tempSock;
			tempSock = NULL;
			m_Dlg->m_LogCtrl.AddString(TEXT("连接成功，可以开始传递消息"));
			m_Dlg->m_SendCtrl.EnableWindow(true);
		}
		else
		{
			m_Dlg->m_LogCtrl.AddString(TEXT("客户端当前的连接尝试失败"));
			delete tempSock;
		}
	else
		m_Dlg->m_LogCtrl.AddString(TEXT("连接套接字初始化失败"));

	CSocket::OnAccept(nErrorCode);
}
