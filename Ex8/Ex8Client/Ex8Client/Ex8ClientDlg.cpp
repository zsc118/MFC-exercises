
// Ex8ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex8Client.h"
#include "Ex8ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CEx8ClientDlg 对话框



CEx8ClientDlg::CEx8ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEx8ClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx8ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG, m_LogCtrl);
	DDX_Control(pDX, IDC_MESSAGE, m_MsgCtrl);
	DDX_Control(pDX, IDC_SEND, m_SendCtrl);
}

BEGIN_MESSAGE_MAP(CEx8ClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, &CEx8ClientDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// CEx8ClientDlg 消息处理程序

BOOL CEx8ClientDlg::OnInitDialog()
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

	m_LogCtrl.AddString(TEXT("正在连接……"));
	if (ClientSock = new CClientSocket(this))
		if (ClientSock->Create())
			if (ClientSock->Connect(TEXT("localhost"), 9547))
			{
				ClientSock->m_File = new CSocketFile(ClientSock);
				ClientSock->m_ArIn = new CArchive(ClientSock->m_File, CArchive::load);
				ClientSock->m_ArOut = new CArchive(ClientSock->m_File, CArchive::store);
				m_LogCtrl.AddString(TEXT("连接成功，可以开始传递消息"));
				m_SendCtrl.EnableWindow(true);
			}
			else
			{
				m_LogCtrl.AddString(TEXT("连接不成功"));
				delete ClientSock;
			}
		else
		{
			m_LogCtrl.AddString(TEXT("初始化失败，请重新启动程序"));
			delete ClientSock;
		}
	else
		m_LogCtrl.AddString(TEXT("初始化失败，请重新启动程序"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEx8ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx8ClientDlg::OnPaint()
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
HCURSOR CEx8ClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEx8ClientDlg::OnBnClickedSend()
{
	CString str;
	m_MsgCtrl.GetWindowText(str);
	if (str.GetLength())
	{
		m_LogCtrl.AddString(TEXT("你发的信息如下:"));
		m_LogCtrl.AddString(str);
		m_LogCtrl.SetCurSel(m_LogCtrl.GetCount() - 1);
		*(ClientSock->m_ArOut) << str;
		ClientSock->m_ArOut->Flush();
	}
	else
		AfxMessageBox(TEXT("消息为空!"));
}
