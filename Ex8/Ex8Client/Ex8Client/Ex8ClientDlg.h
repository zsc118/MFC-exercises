
// Ex8ClientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "Ex8Client.h"
#include "ClientSocket.h"

// CEx8ClientDlg �Ի���
class CEx8ClientDlg : public CDialogEx
{
// ����
public:
	CEx8ClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EX8CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_LogCtrl;
	CEdit m_MsgCtrl;
	CButton m_SendCtrl;
	CClientSocket* ClientSock;
	afx_msg void OnBnClickedSend();
};
