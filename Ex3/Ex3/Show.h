#pragma once
#include "afxwin.h"


// CShow �Ի���

class CShow : public CDialogEx
{
	DECLARE_DYNAMIC(CShow)

public:
	CShow(
		//const CString& s, 
		CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShow();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString showStr;
	afx_msg void OnBnClickedButton1();
	CStatic showWidget;
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
};
