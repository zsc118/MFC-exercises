
// Ex8ClientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Ex8Client.h"
#include "ClientSocket.h"

// CEx8ClientDlg 对话框
class CEx8ClientDlg : public CDialogEx
{
// 构造
public:
	CEx8ClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EX8CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
