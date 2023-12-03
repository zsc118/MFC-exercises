
// Ex8ServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ServSocket.h"
#include "RecvSocket.h"
//#include "resource.h"
#include "Ex8Server.h"

// CEx8ServerDlg �Ի���
class CEx8ServerDlg : public CDialogEx
{
// ����
public:
	CEx8ServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EX8SERVER_DIALOG };

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
	CServSocket *ServSock;
	CRecvSocket *RecvSock;
	afx_msg void OnBnClickedSend();
};
