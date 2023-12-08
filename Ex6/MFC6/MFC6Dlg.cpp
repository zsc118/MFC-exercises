
// MFC6Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC6.h"
#include "MFC6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#include <string.h>
#include <cstdlib>

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


enum Operate{EMPTY,PLUS,MINUS,MUL,DIV,MOD,SQRT,DIV1};
bool isNegative = false;
//CString numStr;
Operate curOp = Operate::EMPTY;
double curNum;

// CMFC6Dlg 对话框



CMFC6Dlg::CMFC6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC6Dlg::IDD, pParent)
	, str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_id, str);
}

BEGIN_MESSAGE_MAP(CMFC6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC6Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC6Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFC6Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC6Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFC6Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC6Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC6Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFC6Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFC6Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFC6Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFC6Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFC6Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFC6Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFC6Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFC6Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFC6Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFC6Dlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CMFC6Dlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC6Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC6Dlg 消息处理程序

BOOL CMFC6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC6Dlg::OnBnClickedButton5()
{
	str += _T("1");
	UpdateData(FALSE);
}


void CMFC6Dlg::OnBnClickedButton6()
{
	str += _T("0");
	UpdateData(FALSE);
}


void CMFC6Dlg::OnBnClickedButton9()
{
	str += _T("2");
	UpdateData(FALSE);
}


void CMFC6Dlg::OnBnClickedButton13()
{
	str += _T("3");
	UpdateData(FALSE);
}


void CMFC6Dlg::OnBnClickedButton4()
{
	str += _T("4");
	UpdateData(FALSE);
}

	void CMFC6Dlg::OnBnClickedButton8()
	{
		str += _T("5");
		UpdateData(FALSE);
	}


	void CMFC6Dlg::OnBnClickedButton12()
	{
		str += _T("6");
		UpdateData(FALSE);
	}


	void CMFC6Dlg::OnBnClickedButton3()
	{
		str += _T("7");
		UpdateData(FALSE);
	}


	void CMFC6Dlg::OnBnClickedButton7()
	{
		str += _T("8");
		UpdateData(FALSE);
	}


	void CMFC6Dlg::OnBnClickedButton11()
	{
		str += _T("9");
		UpdateData(FALSE);
	}


	void CMFC6Dlg::OnBnClickedButton14()
	{
		str += _T(".");
		UpdateData(FALSE);
	}


void CMFC6Dlg::OnBnClickedButton2()
{
	if (!str.IsEmpty())
	{
		str.Delete(str.GetLength() - 1);
		UpdateData(FALSE);
	}
}


void CMFC6Dlg::OnBnClickedButton10()
{
	if (isNegative)
	{
		str = _T("");
	}
	else
	{
		str = _T("-");
	}
	UpdateData(FALSE);
	isNegative = !isNegative;
}


void CMFC6Dlg::OnBnClickedButton19()
{
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP,NULL);  //将字符串转为double类型
	if (!x)
	{
		MessageBox(_T("分母不能为零!"));
		return;
	}
	x = 1 / x;
	str.Format(_T("%g"), x);
	UpdateData(FALSE);
}


void CMFC6Dlg::OnBnClickedButton20()
{
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);  //将字符串转为double类型
	if (x<0.)
	{
		MessageBox(_T("负数不能开方！"));
		return;
	}
	x = sqrt(x);
	str.Format(_T("%g"), x);
	UpdateData(FALSE);
}


double calCurOp(double x,double y,Operate op)
{
	switch (op)
	{
	case PLUS:
		return x + y;
	case MINUS:
		return x - y;
	case MUL:
		return x*y;
	case DIV:
		if (y == 0)
		{
			AfxMessageBox(_T("分母不能为零！"));
			return NAN;
		}
		return x / y;
	case MOD:
		if (y == 0)
		{
			AfxMessageBox(_T("分母不能为零！"));
			return NAN;
		}
		return fmod(x, y);
	default:
		return 0;
	}
}

//void initVar()
//{
//	curOp = Operate::EMPTY;
//	str = _T("");
//
//}

void CMFC6Dlg::OnBnClickedButton18()
{
	if (curOp == Operate::EMPTY)
	{
		curOp = Operate::PLUS;
		CStringA tem(str);
		const char* strP = tem.GetBuffer();
		curNum = strtod(strP, NULL);
		str = _T("");
		UpdateData(FALSE);
		return;
	}
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);
	curNum = calCurOp(curNum, x, curOp);
	str = _T("");
	UpdateData(FALSE);
	if (isnan(curNum))
	{
		curOp = Operate::EMPTY;
		return;
	}
	curOp = Operate::PLUS;
}


void CMFC6Dlg::OnBnClickedButton17()
{
	if (curOp == Operate::EMPTY)
	{
		curOp = Operate::MINUS;
		CStringA tem(str);
		const char* strP = tem.GetBuffer();
		curNum = strtod(strP, NULL);
		str = _T("");
		UpdateData(FALSE);
		return;
	}
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);
	curNum = calCurOp(curNum, x, curOp);
	str = _T("");
	UpdateData(FALSE);
	if (isnan(curNum))
	{
		curOp = Operate::EMPTY;
		return;
	}
	curOp = Operate::MINUS;
}


void CMFC6Dlg::OnBnClickedButton16()
{
	if (curOp == Operate::EMPTY)
	{
		curOp = Operate::MUL;
		CStringA tem(str);
		const char* strP = tem.GetBuffer();
		curNum = strtod(strP, NULL);
		str = _T("");
		UpdateData(FALSE);
		return;
	}
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);
	curNum = calCurOp(curNum, x, curOp);
	str = _T("");
	UpdateData(FALSE);
	if (isnan(curNum))
	{
		curOp = Operate::EMPTY;
		return;
	}
	curOp = Operate::MUL;
}


void CMFC6Dlg::OnBnClickedButton15()
{
	if (curOp == Operate::EMPTY)
	{
		curOp = Operate::DIV;
		CStringA tem(str);
		const char* strP = tem.GetBuffer();
		curNum = strtod(strP, NULL);
		str = _T("");
		UpdateData(FALSE);
		return;
	}
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);
	curNum = calCurOp(curNum, x, curOp);
	str = _T("");
	UpdateData(FALSE);
	if (isnan(curNum))
	{
		curOp = Operate::EMPTY;
		return;
	}
	curOp = Operate::DIV;
}


void CMFC6Dlg::OnBnClickedButton21()
{
	if (curOp == Operate::EMPTY)
	{
		curOp = Operate::MOD;
		CStringA tem(str);
		const char* strP = tem.GetBuffer();
		curNum = strtod(strP, NULL);
		str = _T("");
		UpdateData(FALSE);
		return;
	}
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);
	curNum = calCurOp(curNum, x, curOp);
	str = _T("");
	UpdateData(FALSE);
	if (isnan(curNum))
	{
		curOp = Operate::EMPTY;
		return;
	}
	curOp = Operate::MOD;
}


void CMFC6Dlg::OnBnClickedButton22()
{
	CStringA tem(str);
	const char* strP = tem.GetBuffer();
	double x = strtod(strP, NULL);
	curNum = calCurOp(curNum, x, curOp);
	str.Format(_T("%g"), curNum);
	UpdateData(FALSE);
	curOp = Operate::EMPTY;
}


void CMFC6Dlg::OnBnClickedButton1()
{
	curOp = Operate::EMPTY;
	str = _T("");
	UpdateData(FALSE);
}
