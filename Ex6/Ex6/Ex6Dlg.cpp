
// Ex6Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex6.h"
#include "Ex6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// #include <stack>
#include <vector>
// #include <deque>
#include <stdint.h>
#include <cmath>
// #include "BitStack.h"
// using std::deque;
//  using std::stack;
using std::vector;
// typedef std::stack<double, vector<double>> NumStack;
// typedef std::stack<uint8_t, vector<uint8_t>> OpStack;
// typedef std::stack<size_t, vector<size_t>> IndexStack;

// 判断浮点数是否为整数
// 要求sizeof(double)==8
/*static bool isNotInt(const double &x) noexcept
{
	const long long &t(*(const long long *)(const void *)&x);
	int E((t >> 52 & 0x7ff) - 1023);
	if (E < 0)
		return false;
	if (E > 52)
		return true;
	return (t & 0x000fffffffffffff) << (E + 12);
}
#define JUDGE_INT(x, flag)                                                            \
	{                                                                                 \
		const long long &t(*(const long long *)(const void *)&x);                     \
		int E(((t >> 52) & 0x7ff) - 1023);                                              \
		flag = !(E & 0x80000000) && (E > 52 || (t & 0x000fffffffffffff) << (E + 12)); \
	}
inline bool IsNotInt(const double &x) noexcept
{
	const long long &t(*(const long long *)(const void *)&x);
	int E(((t >> 52) & 0x7ff) - 1023);
	return !(E & 0x80000000) && (E > 52 || (t & 0x000fffffffffffff) << (E + 12));
}
inline double fix(const double &x) noexcept
{
	const unsigned long long &t(*(const unsigned long long *)(const void *)&x);
	short e((2047 & int(t >> 52)) - 1023);
	if (e < 0)
		return 0.;
	if (e > 51)
		return x;
	return *(double *)(void *)&(t & (~((1 << 52 - e) - 1)));
}*/

// 定义用户操作
#define OP_SQRT '\0'
#define OP_LEFT_BRACKET '\1'
#define OP_RIGHT_BRACKET '\2'
#define OP_PLUS '\3'
#define OP_MINUS '\4'
#define OP_MUL '\5'
#define OP_DIV '\6'
#define OP_MOD '\7'
#define OP_POW '\10'
#define NUM_0 '\11'
#define NUM_1 '\12'
#define NUM_2 '\13'
#define NUM_3 '\14'
#define NUM_4 '\15'
#define NUM_5 '\16'
#define NUM_6 '\17'
#define NUM_7 '\20'
#define NUM_8 '\21'
#define NUM_9 '\22'
#define NUM_DOT '\23'
#define NUM_E '\24'
#define OP_CAL '\25'

/*double currentNumber = 0;  // 当前数字
stack<double> numberStack; // 数字栈
stack<uint8_t> opStack;	   // 运算符栈
// 0:默认
// 1:科学计数法
// 2:小数点后数字
stack<uint8_t> numberState; // 数字输入状态
int exponentNumber;			// 指数
double currentDecimal;		// 当前小数位
stack<uint8_t> preInput;	// 历史操作

// 获取当前数字输入状态
inline uint8_t GetNumberState() noexcept
{
	if (numberStack.empty())
		return '\0';
	return numberState.top();
}*/

vector<uint8_t> op; // 用户操作

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum
	{
		IDD = IDD_ABOUTBOX
	};

protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CEx6Dlg 对话框

CEx6Dlg::CEx6Dlg(CWnd *pParent /*=NULL*/)
	: CDialogEx(CEx6Dlg::IDD, pParent), showStr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx6Dlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOW_EXPRESS, showStr);
}

BEGIN_MESSAGE_MAP(CEx6Dlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON12, &CEx6Dlg::OnBnClickedButton12)
ON_BN_CLICKED(IDC_BUTTON9, &CEx6Dlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON10, &CEx6Dlg::OnBnClickedButton10)
ON_BN_CLICKED(IDC_BUTTON11, &CEx6Dlg::OnBnClickedButton11)
ON_BN_CLICKED(IDC_BUTTON6, &CEx6Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &CEx6Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CEx6Dlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON4, &CEx6Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON3, &CEx6Dlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON5, &CEx6Dlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON13, &CEx6Dlg::OnBnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON14, &CEx6Dlg::OnBnClickedButton14)
ON_BN_CLICKED(IDC_BUTTON2, &CEx6Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON1, &CEx6Dlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON23, &CEx6Dlg::OnBnClickedButton23)
ON_BN_CLICKED(IDC_BUTTON24, &CEx6Dlg::OnBnClickedButton24)
ON_BN_CLICKED(IDC_BUTTON15, &CEx6Dlg::OnBnClickedButton15)
ON_BN_CLICKED(IDC_BUTTON16, &CEx6Dlg::OnBnClickedButton16)
ON_BN_CLICKED(IDC_BUTTON17, &CEx6Dlg::OnBnClickedButton17)
ON_BN_CLICKED(IDC_BUTTON18, &CEx6Dlg::OnBnClickedButton18)
ON_BN_CLICKED(IDC_BUTTON19, &CEx6Dlg::OnBnClickedButton19)
ON_BN_CLICKED(IDC_BUTTON20, &CEx6Dlg::OnBnClickedButton20)
ON_BN_CLICKED(IDC_BUTTON21, &CEx6Dlg::OnBnClickedButton21)
ON_BN_CLICKED(IDC_BUTTON22, &CEx6Dlg::OnBnClickedButton22)
END_MESSAGE_MAP()

// CEx6Dlg 消息处理程序

BOOL CEx6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu *pSysMenu = GetSystemMenu(FALSE);
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
	SetIcon(m_hIcon, TRUE);	 // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void CEx6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx6Dlg::OnPaint()
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

// 当用户拖动最小化窗口时系统调用此函数取得光标
// 显示。
HCURSOR CEx6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#define JUDGE_CALCATED                      \
	if (!op.empty() && op.back() == OP_CAL) \
	{                                       \
		op.clear();                         \
		showStr = TEXT("");                 \
	}

#define NUM_CLICKED(x)     \
	JUDGE_CALCATED         \
	op.push_back(NUM_##x); \
	showStr += TEXT(#x);   \
	UpdateData(FALSE);

// 0
void CEx6Dlg::OnBnClickedButton12()
{
	/*switch (GetNumberState())
	{
	case '\0':
		currentNumber *= 10;
		break;
	case '\1':
		exponentNumber *= 10;
		break;
	default:
		currentDecimal /= 10;
	}
	showStr += TEXT("0");
	UpdateData(FALSE);
	preInput.push(NUM_0);*/
	NUM_CLICKED(0)
}

// 1
void CEx6Dlg::OnBnClickedButton9()
{
	/*switch (GetNumberState())
	{
	case '\0':
		++(currentNumber *= 10);
		break;
	case '\1':
		++(exponentNumber *= 10);
		break;
	default:
		currentNumber += currentDecimal /= 10;
	}
	showStr += TEXT("1");
	UpdateData(FALSE);
	preInput.push(NUM_1);*/
	NUM_CLICKED(1)
}

/*#define CLICK_NUMBER(x)                              \
	switch (GetNumberState())                        \
	{                                                \
	case '\0':                                       \
		(currentNumber *= 10) += x;                  \
		break;                                       \
	case '\1':                                       \
		(exponentNumber *= 10) += x;                 \
		break;                                       \
	default:                                         \
		currentNumber += x * (currentDecimal /= 10); \
	}                                                \
	showStr += TEXT(#x);                             \
	UpdateData(FALSE);*/

// 2
void CEx6Dlg::OnBnClickedButton10()
{
	/*CLICK_NUMBER(2)
	preInput.push(NUM_2);*/
	NUM_CLICKED(2)
}

// 3
void CEx6Dlg::OnBnClickedButton11()
{
	/*CLICK_NUMBER(3)
	preInput.push(NUM_3);*/
	NUM_CLICKED(3)
}

// 4
void CEx6Dlg::OnBnClickedButton6()
{
	/*CLICK_NUMBER(4)
	preInput.push(NUM_4);*/
	NUM_CLICKED(4)
}

// 5
void CEx6Dlg::OnBnClickedButton7()
{
	/*CLICK_NUMBER(5)
	preInput.push(NUM_5);*/
	NUM_CLICKED(5)
}

// 6
void CEx6Dlg::OnBnClickedButton8()
{
	/*CLICK_NUMBER(6)
	preInput.push(NUM_6);*/
	NUM_CLICKED(6)
}

// 7
void CEx6Dlg::OnBnClickedButton4()
{
	/*CLICK_NUMBER(7)
	preInput.push(NUM_7);*/
	NUM_CLICKED(7)
}

// 8
void CEx6Dlg::OnBnClickedButton3()
{
	/*CLICK_NUMBER(8)
	preInput.push(NUM_8);*/
	NUM_CLICKED(8)
}

// 9
void CEx6Dlg::OnBnClickedButton5()
{
	/*CLICK_NUMBER(9)
	preInput.push(NUM_9);*/
	NUM_CLICKED(9)
}

// x10^*
void CEx6Dlg::OnBnClickedButton13()
{
	/*if(GetNumberState())
	{
		MessageBox(TEXT("数据输入有误!"));
		return;
	}
	exponentNumber = 0;
	showStr += TEXT("E");
	numberState.push('\1');
	UpdateData(FALSE);
	preInput.push(NUM_E);*/
	NUM_CLICKED(E)
}

// .
void CEx6Dlg::OnBnClickedButton14()
{
	/*currentDecimal = 1.;
	showStr += TEXT(".");
	UpdateData(FALSE);
	numberState.push('\2');
	preInput.push(NUM_DOT);*/
	JUDGE_CALCATED
	op.push_back(NUM_DOT);
	showStr += TEXT(".");
	UpdateData(FALSE);
}

// backspace
void CEx6Dlg::OnBnClickedButton2()
{
	/*if(preInput.empty())
		return;
	switch (preInput.top())
	{
	case NUM_E:
	case NUM_DOT:
		numberState.pop();
	case NUM_0:
	case NUM_1:
	case NUM_2:
	case NUM_3:
	case NUM_4:
	case NUM_5:
	case NUM_6:
	case NUM_7:
	case NUM_8:
	case NUM_9:
		showStr.Delete(showStr.GetLength() - 1, 1);
		break;
	}
	preInput.pop();
	UpdateData(FALSE);*/
	if (op.empty())
		return;
	switch (op.back())
	{
	case OP_MOD:
		showStr.Delete(showStr.GetLength() - 3, 3);
		break;
	case OP_SQRT:
		showStr.Delete(showStr.GetLength() - 5, 5);
		break;
	default:
		showStr.Delete(showStr.GetLength() - 1, 1);
	}
	op.pop_back();
	UpdateData(FALSE);
}

/*#define CLEAR_STACK(x) \
	while (x.size())   \
		x.pop();*/

// clear
void CEx6Dlg::OnBnClickedButton1()
{
	/*CLEAR_STACK(numberStack)
	CLEAR_STACK(preInput)
	CLEAR_STACK(numberState)
	CLEAR_STACK(opStack)
	currentNumber = 0.;
	showStr = TEXT("");
	UpdateData(FALSE);*/
	// CLEAR_STACK(op)
	op.clear();
	showStr = TEXT("");
	UpdateData(FALSE);
}

// (
void CEx6Dlg::OnBnClickedButton23()
{
	JUDGE_CALCATED
	op.push_back(OP_LEFT_BRACKET);
	showStr += TEXT("(");
	UpdateData(FALSE);
}

// )
void CEx6Dlg::OnBnClickedButton24()
{
	JUDGE_CALCATED
	op.push_back(OP_RIGHT_BRACKET);
	showStr += TEXT(")");
	UpdateData(FALSE);
}

// +
void CEx6Dlg::OnBnClickedButton15()
{
	JUDGE_CALCATED
	op.push_back(OP_PLUS);
	showStr += TEXT("+");
	UpdateData(FALSE);
}

// -
void CEx6Dlg::OnBnClickedButton16()
{
	JUDGE_CALCATED
	op.push_back(OP_MINUS);
	showStr += TEXT("-");
	UpdateData(FALSE);
}

// *
void CEx6Dlg::OnBnClickedButton17()
{
	JUDGE_CALCATED
	op.push_back(OP_MUL);
	showStr += TEXT("*");
	UpdateData(FALSE);
}

// /
void CEx6Dlg::OnBnClickedButton18()
{
	JUDGE_CALCATED
	op.push_back(OP_DIV);
	showStr += TEXT("/");
	UpdateData(FALSE);
}

// ^
void CEx6Dlg::OnBnClickedButton19()
{
	JUDGE_CALCATED
	op.push_back(OP_POW);
	showStr += TEXT("^");
	UpdateData(FALSE);
}

// sqrt
void CEx6Dlg::OnBnClickedButton20()
{
	JUDGE_CALCATED
	op.push_back(OP_SQRT);
	showStr += TEXT("sqrt(");
	UpdateData(FALSE);
}

// mod
void CEx6Dlg::OnBnClickedButton21()
{
	JUDGE_CALCATED
	op.push_back(OP_MOD);
	showStr += TEXT("mod");
	UpdateData(FALSE);
}

#define CAL_CASE_NUM(curNum)             \
	if (numState & '\2')                 \
		if (numState & '\1')             \
			if (numState & '\10')        \
				e -= curNum * (d /= 10); \
			else                         \
				e += curNum * (d /= 10); \
		else if (numState & '\10')       \
			(e *= 10) -= curNum;         \
		else                             \
			(e *= 10) += curNum;         \
	else if (numState & '\1')            \
		if (numState & '\4')             \
			x -= curNum * (d /= 10);     \
		else                             \
			x += curNum * (d /= 10);     \
	else if (numState & '\4')            \
		(x *= 10) -= curNum;             \
	else                                 \
		(x *= 10) += curNum;             \
	break;

// 运算符优先级
/*#define OP_PLUS_STACK '\0'
#define OP_MINUS_STACK '\0'
#define OP_MUL_STACK '\1'
#define OP_DIV_STACK '\1'
#define OP_POW_STACK '\2'
#define OP_SQRT_STACK '\3'*/
#define OP_PRIORITY(op1, op2) (op1 < op2 && (op1 != OP_PLUS || op2 != OP_MINUS) && (op1 != OP_MUL || op2 != OP_DIV && op2 != OP_MOD) && (op1 != OP_DIV || op2 != OP_MOD)) // op2的优先级大于op1

// 合并指数
#define CAL_NUM_WITH_EXP \
	if (numState & '\2') \
		x *= pow(10., e);

// 合并数据并重置状态
#define SET_NUM_STATE \
	CAL_NUM_WITH_EXP  \
	numState = '\0';

#define ADD_CAL_SIGN         \
	if (op.back() != OP_CAL) \
		op.push_back(OP_CAL);

#define THROW_ERROR(condition, err_msg) \
	if (condition)                      \
	{                                   \
		MessageBox(TEXT(err_msg));      \
		ADD_CAL_SIGN                    \
		return;                         \
	}

// 进行计算, 结果保存在num1中
/*#define CAL_RES_WITH_OP(num1, num2, Operater) switch (Operater)
#define CAL_RES_WITHIN_OP(Operater) \
	x Operator numStack.top();      \
	numStack.pop();*/

// #define _CAL_RES_WITH_CONDITION(condition)                                                \
// 	temp_op = opStack.back();                                                             \
// 	while (condition)                                                                     \
// 	{                                                                                     \
// 		switch (temp_op)                                                                  \
// 		{                                                                                 \
// 		case OP_PLUS:                                                                     \
// 			x += numStack.back();                                                         \
// 			break;                                                                        \
// 		case OP_MINUS:                                                                    \
// 			x = numStack.back() - x;                                                      \
// 			break;                                                                        \
// 		case OP_MUL:                                                                      \
// 			x *= numStack.back();                                                         \
// 			break;                                                                        \
// 		case OP_DIV:                                                                      \
// 			THROW_ERROR(!x, "分母为零!")                                                  \
// 			x = numStack.back() / x;                                                      \
// 			break;                                                                        \
// 		case OP_MOD:                                                                      \
// 			THROW_ERROR(!x, "分母为零!")                                                  \
// 			x = fmod(numStack.back(), x);                                                 \
// 			/*THROW_ERROR(IsNotInt(x) || IsNotInt(numStack.back()), "非整数取余!")*/ \
// 			/*{                                                                  */       \
// 			/*	long long X_integer(x), Y_integer(numStack.back());              */        \
// 			/*	x = Y_integer % X_integer;                                       */        \
// 			/*}                                                                  */       \
// 			break;                                                                        \
// 		case OP_POW:                                                                      \
// 			THROW_ERROR(isnan(x = pow(numStack.back(), x)), "乘幂有误!")                  \
// 		}                                                                                 \
// 		numStack.pop_back();                                                              \
// 		opStack.pop_back();                                                               \
// 		if (opStack.empty())                                                              \
// 			break;                                                                        \
// 		temp_op = opStack.back();                                                         \
// 	}

/*#define CAL_RES_WITH_CONDITION(condition)  \
	if (!opStack.empty())                  \
	{                                      \
		_CAL_RES_WITH_CONDITION(condition) \
	}

#define CAL_RES_WITH_OP(Operator_ID) CAL_RES_WITH_CONDITION(OP_PRIORITY(Operator_ID, temp_op))

#define CAL_CASE_OP(Operator_ID)    \
	SET_NUM_STATE                   \
	CAL_RES_WITH_OP(Operator_ID)    \
	opStack.push_back(Operator_ID); \
	numStack.push_back(x);          \
	x = 0.;                         \
	break;

#define CAL_CASE_OP_NOTCAL(Operator_ID) \
	SET_NUM_STATE                       \
	opStack.push_back(Operator_ID);     \
	numStack.push_back(x);              \
	x = 0.;                             \
	break;*/

// #define CAL_RES_ALL(condition)                        \
// 	if (!opStack.empty())                             \
// 	{                                                 \
// 		opPointer = opStack.end();                    \
// 		numPointer = numStack.end();                  \
// 		while (*--opPointer == OP_POW && (condition)) \
// 		{                                             \
// 			THROW_ERROR(opPointer == opStack.begin(),"括号")        \
// 		}                                             \
// 	}

/*#define _CAL_POW                                                         \
	opP = opStack.end();                                                 \
	--(numP = numStack.end());                                           \
	while (opP != opStack.begin())                                       \
	{                                                                    \
		if (*opP-- != OP_POW)                                            \
			break;                                                       \
		--numP;                                                          \
		THROW_ERROR(isnan(*numP = pow(*numP, *(numP + 1))), "乘幂有误!") \
	}*/
#define CAL_RANGE_POW(p1, p2)                                                \
	while (p1 != p2)                                                         \
	{                                                                        \
		THROW_ERROR(isnan(*(p1 + 1) = pow(*p1, *(p1 + 1))), "乘幂计算有误!") \
		++p1;                                                                \
	}
#define __CAL_MDM(num1, num2, op_ID)      \
	switch (op_ID)                        \
	{                                     \
	case OP_MUL:                          \
		num2 *= num1;                     \
		break;                            \
	case OP_DIV:                          \
		THROW_ERROR(!(num2), "除数为零!") \
		num2 = num1 / num2;               \
		break;                            \
	case OP_MOD:                          \
		THROW_ERROR(!(num2), "除数为零!") \
		num2 = fmod(num1, num2);          \
	}
#define CAL_RANGE_MDM(np1, np2, op)        \
	while (np1 != np2)                     \
	{                                      \
		__CAL_MDM(*np1, *(np1 + 1), *op++) \
		++np1;                             \
	}
#define __CAL_PM(num1, num2, op_ID) \
	if (op_ID == OP_PLUS)           \
		num2 += num1;               \
	else                            \
		num2 = num1 - num2;
#define CAL_RANGE_PM(np1, np2, op)        \
	while (np1 != np2)                    \
	{                                     \
		__CAL_PM(*np1, *(np1 + 1), *op++) \
		++np1;                            \
	}
#define FIND_RANGE(np1, np2, op, top, condition, opLowerBound) \
	top = op;                                                  \
	while (op != opLowerBound)                                 \
		if (condition)                                         \
		{                                                      \
			++op;                                              \
			break;                                             \
		}                                                      \
	np1 = np2 - (top - op);
#define FIND_RANGE_POW(np1, np2, op, top, opLowerBound) FIND_RANGE(np1, np2, op, top, *--op != OP_POW, opLowerBound)
#define FIND_RANGE_MDM(np1, np2, op, top, opLowerBound) FIND_RANGE(np1, np2, op, top, *--op != OP_MUL && *op != OP_DIV && *op != OP_MOD, opLowerBound)
#define FIND_RANGE_PM(np1, np2, op, top, opLowerBound) FIND_RANGE(np1, np2, op, top, *--op != OP_PLUS && *op != OP_MINUS, opLowerBound)
#define CAL_REMOVE(np, op)                \
	if (op != opStack.end())              \
		opStack.erase(op, opStack.end()); \
	if (np != numStack.end())             \
		numStack.erase(np, numStack.end());
#define _CAL_POW(np1, np2, op, top, tnp, opLowerBound) \
	np2 = numStack.end() - 1;                          \
	op = opStack.end();                                \
	FIND_RANGE_POW(np1, np2, op, top, opLowerBound)    \
	top = op;                                          \
	tnp = np1;                                         \
	CAL_RANGE_POW(np1, np2)                            \
	*tnp = *np2;
#define CAL_POW(np1, np2, op, top, tnp, opLowerBound) \
	_CAL_POW(np1, np2, op, top, tnp, opLowerBound)    \
	++tnp;                                            \
	CAL_REMOVE(tnp, top)
#define _CAL_MDM(np1, np2, op, top, tnp, opLowerBound) \
	_CAL_POW(np1, np2, op, top, tnp, opLowerBound)     \
	op = top;                                          \
	np2 = tnp;                                         \
	FIND_RANGE_MDM(np1, np2, op, top, opLowerBound)    \
	tnp = np1;                                         \
	top = op;                                          \
	CAL_RANGE_MDM(np1, np2, op)                        \
	*tnp = *np2;
#define CAL_MDM(np1, np2, op, top, tnp, opLowerBound) \
	_CAL_MDM(np1, np2, op, top, tnp, opLowerBound)    \
	++tnp;                                            \
	CAL_REMOVE(tnp, top)
#define _CAL_PM(np1, np2, op, top, tnp, opLowerBound) \
	_CAL_MDM(np1, np2, op, top, tnp, opLowerBound)    \
	op = top;                                         \
	np2 = tnp;                                        \
	FIND_RANGE_PM(np1, np2, op, top, opLowerBound)    \
	tnp = np1;                                        \
	top = op;                                         \
	CAL_RANGE_PM(np1, np2, op)                        \
	*tnp = *np2;
#define CAL_PM(np1, np2, op, top, tnp, opLowerBound) \
	_CAL_PM(np1, np2, op, top, tnp, opLowerBound)    \
	++tnp;                                           \
	CAL_REMOVE(tnp, top)
#define CASE_POW CAL_POW(numP1, numP2, opP1, opP2, numP3, opStack.begin())
#define CASE_MDM CAL_MDM(numP1, numP2, opP1, opP2, numP3, opStack.begin())
#define CASE_PM CAL_PM(numP1, numP2, opP1, opP2, numP3, opStack.begin())
#define CASE_OP(ID)        \
	SET_NUM_STATE          \
	numStack.push_back(x); \
	x = 0.;                \
	opStack.push_back(ID); \
	break;
#define CASE_OPC(ID, case) \
	SET_NUM_STATE          \
	numStack.push_back(x); \
	if (!numStack.empty()) \
	{CASE_##case} x = 0.;  \
	opStack.push_back(ID); \
	break;

// =
void CEx6Dlg::OnBnClickedButton22()
{
	/*if (op.back() == OP_CAL)
		return;
	double x(0.), e, d; // x:当前数字 e:指数 d:小数位
	vector<double> numStack;
	vector<uint8_t> opStack;
	vector<uint8_t>::iterator i(op.begin());
	uint8_t numState('\0'); // 数字输入状态: 第1位:是否在输入小数 第2位:是否在输入指数
	// 第3位:是否为负数 第4位:是否为负指数
	uint8_t temp_op;
	vector<double>::iterator numPointer, tem_numP1, tem_numP2;
	vector<uint8_t>::iterator opPointer, tem_opP1, tem_opP2;
	do
		switch (*i)
		{
		case NUM_0:
			CAL_CASE_NUM(0)
		case NUM_1:
			CAL_CASE_NUM(1)
		case NUM_2:
			CAL_CASE_NUM(2)
		case NUM_3:
			CAL_CASE_NUM(3)
		case NUM_4:
			CAL_CASE_NUM(4)
		case NUM_5:
			CAL_CASE_NUM(5)
		case NUM_6:
			CAL_CASE_NUM(6)
		case NUM_7:
			CAL_CASE_NUM(7)
		case NUM_8:
			CAL_CASE_NUM(8)
		case NUM_9:
			CAL_CASE_NUM(9)
		case NUM_DOT:
			numState |= '\1';
			d = 1.;
			break;
		case NUM_E:
			numState = '\2';
			e = 0.;
			break;
		case OP_PLUS:
			CAL_CASE_OP(OP_PLUS)
		case OP_MINUS: // 可能为减号或取负, 需要分别讨论
			if (i == op.begin() || !opStack.empty() && (opStack.back() == OP_LEFT_BRACKET || opStack.back() == OP_SQRT))
			{
				numState |= '\4';
				break;
			}
			if (*(i - 1) == NUM_E)
			{
				numState |= '\10';
				break;
			}
			CAL_CASE_OP(OP_MINUS)
		case OP_MUL:
			CAL_CASE_OP(OP_MUL)
		case OP_DIV:
			CAL_CASE_OP(OP_DIV)
		case OP_MOD:
			CAL_CASE_OP(OP_MOD)
		case OP_POW:
			CAL_CASE_OP_NOTCAL(OP_POW)
		case OP_LEFT_BRACKET:
			opStack.push_back(OP_LEFT_BRACKET);
			break;
		case OP_RIGHT_BRACKET:
			// CAL_RES_WITH_CONDITION(temp_op != OP_LEFT_BRACKET && temp_op != OP_SQRT)
#define BRACKET_CONDITION(OPPOINTER) *OPPOINTER != OP_LEFT_BRACKET &&*OPPOINTER != OP_SQRT
#define BRACKET_REMOVE(OPPOINTER, NUMPOINTER)   \
	opStack.erase(OPPOINTER, opStack.end());    \
	numStack.erase(NUMPOINTER, numStack.end()); \
	goto F1;
#define BRACKET_BREAK(OPPOINTER, NUMPOINTER)  \
	if (*OPPOINTER == OP_LEFT_BRACKET)        \
	{                                         \
		BRACKET_REMOVE(OPPOINTER, NUMPOINTER) \
	}                                         \
	else if (*OPPOINTER == OP_SQRT)           \
	{                                         \
		THROW_ERROR(x < 0, "对负数开方!")     \
		x = sqrt(x);                          \
		BRACKET_REMOVE(OPPOINTER, NUMPOINTER) \
	}
#define CAL_MUL_DIV_MOD(num1, num2, OPID) \
	switch (OPID)                         \
	{                                     \
	case OP_MUL:                          \
		num2 *= num1;                     \
		break;                            \
	case OP_DIV:                          \
		THROW_ERROR(num2, "分母为零!")    \
		num2 = num1 / (num2);             \
		break;                            \
	case OP_MOD:                          \
		THROW_ERROR(num2, "分母为零!")    \
		num2 = fmod(num1, num2);          \
	}
#define CAL_PLUS_MINUS(num1, num2, OPID) \
	if (OPID == OP_PLUS)                 \
		num2 += num1;                    \
	else                                 \
		num2 = num1 - num2;
			SET_NUM_STATE
			THROW_ERROR(opStack.empty(), "括号不匹配!")
			opPointer = opStack.end();
			numPointer = numStack.end();
			while (*--opPointer == OP_POW)
			{
				THROW_ERROR(opPointer == opStack.begin(), "括号不匹配!")
				THROW_ERROR(x = pow(*--numPointer, x), "乘幂输入有误!")
			}
			BRACKET_BREAK(opPointer, numPointer)
			if (*opPointer != OP_MUL && *opPointer != OP_DIV && *opPointer != OP_MOD)
				goto F2;
			*numPointer = x;
			tem_opP2 = opPointer;
			while (*--opPointer == OP_MUL || *opPointer == OP_DIV || *opPointer == OP_MOD)
			{
				THROW_ERROR(opPointer == opStack.begin(), "括号不匹配!")
				--numPointer;
			}
			tem_numP1 = numPointer, tem_opP1 = opPointer;
			while (opPointer != tem_opP2)
			{
				++numPointer;
				CAL_MUL_DIV_MOD(*(numPointer - 1), *numPointer, *++opPointer)
			}
			x = *numPointer;
			opPointer = tem_opP1;
			*(numPointer = tem_numP1) = x;
		F2:
			if (*opPointer != OP_PLUS && *opPointer != OP_MINUS)
			{
				THROW_ERROR(BRACKET_CONDITION(tem_opP1), "括号不匹配!")
				BRACKET_BREAK(tem_opP1, tem_numP1)
			}
			while (*--opPointer == OP_PLUS || *opPointer == OP_MINUS)
			{
				THROW_ERROR(opPointer == opStack.begin(), "括号不匹配!")
				--numPointer;
			}
			THROW_ERROR(opPointer == opStack.begin(), "括号不匹配!")
			tem_numP2 = numPointer, tem_opP2 = opPointer;
			while (opPointer != tem_opP1)
			{
				++numPointer;
				CAL_PLUS_MINUS(*(numPointer - 1), *numPointer, *++opPointer)
			}
			x = *numPointer;
			if (*tem_opP2 == OP_SQRT)
			{
				THROW_ERROR(x < 0, "对负数开方!")
				x = sqrt(x);
				opStack.erase(tem_opP2, opStack.end());
				numStack.erase(tem_numP2, numStack.end());
			}
			else if (*tem_opP2 == OP_LEFT_BRACKET)
			{
				opStack.erase(tem_opP2, opStack.end());
				numStack.erase(tem_numP2, numStack.end());
			}
		F1:
			break;
		// THROW_ERROR(opStack.empty(), "括号个数不匹配!")
		// if (opStack.back() == OP_SQRT)
		// {
		// 	THROW_ERROR(x < 0, "对负数开方!")
		// 	x = sqrt(x);
		// }
		// opStack.pop_back(); // 将左括号或根号出栈
		case OP_SQRT:
			opStack.push_back(OP_SQRT);
		}
	while (++i != op.end());
	CAL_NUM_WITH_EXP
	// CAL_RES_WITH_CONDITION(!opStack.empty())
#define FINAL_BREAK      \
	if (opStack.empty()) \
		goto F3;
#define FINAL_POINTER_BREAK(POINTER) \
	if (POINTER == opStack.begin())  \
		goto F3;
	if (!opStack.empty())
	{
		opPointer = opStack.end();
		numPointer = numStack.end();
		while (*--opPointer == OP_POW)
		{
			THROW_ERROR(x = pow(*--numPointer, x), "乘幂输入有误!")
			FINAL_POINTER_BREAK(opPointer)
		}
		// FINAL_BREAK
		if (*opPointer != OP_MUL && *opPointer != OP_DIV && *opPointer != OP_MOD)
			goto F4;
		//*numPointer = x;
		tem_opP2 = --opPointer;
		while (*opPointer == OP_MUL || *opPointer == OP_DIV || *opPointer == OP_MOD)
		{
			if (opPointer == opStack.begin())
			{
				CAL_MUL_DIV_MOD(*(numPointer - 1), *numPointer, *opPointer)
				while (opPointer != tem_opP2)
				{
					++numPointer;
					CAL_MUL_DIV_MOD(*(numPointer - 1), *numPointer, *++opPointer)
				}
				x = *numPointer;
				goto F3;
			}
			--numPointer;
		}
		tem_numP1 = numPointer, tem_opP1 = opPointer;
		while (opPointer != tem_opP2)
		{
			++numPointer;
			CAL_MUL_DIV_MOD(*(numPointer - 1), *numPointer, *++opPointer)
		}
		x = *numPointer;
		opPointer = tem_opP1;
		*(numPointer = tem_numP1) = x;
	F4:
		THROW_ERROR(*opPointer != OP_PLUS && *opPointer != OP_MINUS, "表达式有误!")
		while (*--opPointer == OP_PLUS || *opPointer == OP_MINUS)
		{
			if (opPointer == opStack.begin())
			{
				CAL_PLUS_MINUS(*(numPointer - 1), *numPointer, *opPointer)
				break;
			}
			--numPointer;
		}
		while (opPointer != tem_opP1)
		{
			++numPointer;
			CAL_PLUS_MINUS(*(numPointer - 1), *numPointer, *++opPointer)
		}
		x = *numPointer;
	}
F3:
	CString s;
	s.Format(TEXT("=%f"), x);
	showStr += s;
	UpdateData(FALSE);
	ADD_CAL_SIGN*/
	if (op.back() == OP_CAL)
		return;
	double x(0.), e, d; // x:当前数字 e:指数 d:小数位
	vector<double> numStack;
	vector<uint8_t> opStack;
	vector<uint8_t>::iterator i(op.begin()), opP1, opP2, opP3;
	vector<double>::iterator numP1, numP2, numP3;
	uint8_t numState('\0'); // 数字输入状态: 第1位:是否在输入小数 第2位:是否在输入指数
	// 第3位:是否为负数 第4位:是否为负指数
	// IndexStack bracketPosStack;
	// CBitStack bracketStack; // true表示开方, 否则为左括号
	do
		switch (*i)
		{
		case NUM_0:
			CAL_CASE_NUM(0)
		case NUM_1:
			CAL_CASE_NUM(1)
		case NUM_2:
			CAL_CASE_NUM(2)
		case NUM_3:
			CAL_CASE_NUM(3)
		case NUM_4:
			CAL_CASE_NUM(4)
		case NUM_5:
			CAL_CASE_NUM(5)
		case NUM_6:
			CAL_CASE_NUM(6)
		case NUM_7:
			CAL_CASE_NUM(7)
		case NUM_8:
			CAL_CASE_NUM(8)
		case NUM_9:
			CAL_CASE_NUM(9)
		case NUM_DOT:
			numState |= '\1';
			d = 1.;
			break;
		case NUM_E:
			numState = '\2';
			e = 0.;
			break;
		case OP_PLUS:
			CASE_OPC(OP_PLUS, MDM)
		case OP_MINUS:
			if (i == op.begin() || *(i - 1) == OP_SQRT || *(i - 1) == OP_LEFT_BRACKET)
			{
				numState |= '\4';
				break;
			}
			if (*(i - 1) == NUM_E)
			{
				numState |= '\10';
				break;
			}
			CASE_OPC(OP_MINUS, MDM)
		case OP_MUL:
			CASE_OPC(OP_MUL, POW)
		case OP_DIV:
			CASE_OPC(OP_DIV, POW)
		case OP_POW:
			CASE_OP(OP_POW)
		case OP_MOD:
			CASE_OPC(OP_MOD, POW)
		case OP_SQRT:
			opStack.push_back(OP_SQRT);
			break;
		case OP_LEFT_BRACKET:
			opStack.push_back(OP_LEFT_BRACKET);
			break;
		case OP_RIGHT_BRACKET:
			SET_NUM_STATE
			numStack.push_back(x);
			CASE_PM
			THROW_ERROR(opStack.empty() || opStack.back() != OP_SQRT && opStack.back() != OP_LEFT_BRACKET, "括号不匹配!")
			if (opStack.back() == OP_SQRT)
			{
				THROW_ERROR(numStack.back() < 0, "负数不能开方!")
				numStack.back() = sqrt(numStack.back());
			}
			opStack.pop_back();
			x = numStack.back();
			numStack.pop_back();
		}
	while (++i != op.end());
	CAL_NUM_WITH_EXP
	numStack.push_back(x);
	CASE_PM
	CString s;
	s.Format(TEXT("=%f"), numStack.back());
	showStr += s;
	UpdateData(FALSE);
	ADD_CAL_SIGN
}

BOOL CEx6Dlg::PreTranslateMessage(MSG *pMsg)
{
	if (::TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}
