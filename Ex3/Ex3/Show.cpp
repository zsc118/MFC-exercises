// Show.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex3.h"
#include "Show.h"
#include "afxdialogex.h"


// CShow 对话框

IMPLEMENT_DYNAMIC(CShow, CDialogEx)

CShow::CShow(
//const CString& s, 
CWnd* pParent /*=NULL*/)
	: CDialogEx(CShow::IDD, pParent)
	, showStr(_T(""))
{
	//showWidget.SetWindowTextW(s);
}

CShow::~CShow()
{
}

void CShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOW1, showStr);
	DDX_Control(pDX, IDC_SHOW1, showWidget);
}


BEGIN_MESSAGE_MAP(CShow, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CShow::OnBnClickedButton1)
END_MESSAGE_MAP()


// CShow 消息处理程序


void CShow::OnBnClickedButton1()
{
	OnOK();
}


BOOL CShow::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	UpdateData(FALSE);

	return CDialogEx::Create(lpszTemplateName, pParentWnd);
}
