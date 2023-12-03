// ShowInformation.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex3.h"
#include "ShowInformation.h"
#include "afxdialogex.h"


// ShowInformation 对话框

IMPLEMENT_DYNAMIC(ShowInformation, CDialog)

ShowInformation::ShowInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowInformation::IDD, pParent)
	, information(_T(""))
{

}

ShowInformation::~ShowInformation()
{
}

void ShowInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_SHOW, information);
	DDX_Text(pDX, IDC_SHOW, information);
}


BEGIN_MESSAGE_MAP(ShowInformation, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &ShowInformation::OnBnClickedButton1)
END_MESSAGE_MAP()


// ShowInformation 消息处理程序
// ShowInformation.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex3.h"
#include "ShowInformation.h"
#include "afxdialogex.h"


// ShowInformation 对话框

//IMPLEMENT_DYNAMIC(ShowInformation, CDialogEx)

//ShowInformation::ShowInformation(CWnd* pParent /*=NULL*/)
//	: CDialogEx(ShowInformation::IDD, pParent)
//{
//
//}
//
//ShowInformation::~ShowInformation()
//{
//}
//
//void ShowInformation::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}


//BEGIN_MESSAGE_MAP(ShowInformation, CDialogEx)
//END_MESSAGE_MAP()


// ShowInformation 消息处理程序


void ShowInformation::OnBnClickedButton1()
{
	OnOK();
}
