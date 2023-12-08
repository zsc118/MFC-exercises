
// MFC6Dlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// CMFC6Dlg �Ի���



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


// CMFC6Dlg ��Ϣ�������

BOOL CMFC6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	double x = strtod(strP,NULL);  //���ַ���תΪdouble����
	if (!x)
	{
		MessageBox(_T("��ĸ����Ϊ��!"));
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
	double x = strtod(strP, NULL);  //���ַ���תΪdouble����
	if (x<0.)
	{
		MessageBox(_T("�������ܿ�����"));
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
			AfxMessageBox(_T("��ĸ����Ϊ�㣡"));
			return NAN;
		}
		return x / y;
	case MOD:
		if (y == 0)
		{
			AfxMessageBox(_T("��ĸ����Ϊ�㣡"));
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
