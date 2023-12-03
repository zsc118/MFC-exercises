#pragma once
#include "afxwin.h"


// CShow 对话框

class CShow : public CDialogEx
{
	DECLARE_DYNAMIC(CShow)

public:
	CShow(
		//const CString& s, 
		CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShow();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString showStr;
	afx_msg void OnBnClickedButton1();
	CStatic showWidget;
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
};
