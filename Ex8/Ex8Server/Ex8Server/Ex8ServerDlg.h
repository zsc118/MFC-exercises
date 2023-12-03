
// Ex8ServerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ServSocket.h"
#include "RecvSocket.h"
//#include "resource.h"
#include "Ex8Server.h"

// CEx8ServerDlg 对话框
class CEx8ServerDlg : public CDialogEx
{
// 构造
public:
	CEx8ServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EX8SERVER_DIALOG };

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
	CServSocket *ServSock;
	CRecvSocket *RecvSock;
	afx_msg void OnBnClickedSend();
};
