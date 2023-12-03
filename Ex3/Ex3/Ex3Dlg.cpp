
// Ex3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex3.h"
#include "Ex3Dlg.h"
#include "afxdialogex.h"
//#include "ShowInformation.h"
#include "Show.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CEx3Dlg �Ի���



CEx3Dlg::CEx3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEx3Dlg::IDD, pParent)
	, name(_T(""))
	, sex(FALSE)
	, email(_T(""))
	, others(_T(""))
	, exercise(FALSE)
	, game(FALSE)
	, music(FALSE)
	, movie(FALSE)
	, travel(FALSE)
	, read(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Radio(pDX, IDC_RADIO1, sex);
	DDX_Text(pDX, IDC_EDIT3, email);
	DDX_Control(pDX, IDC_COMBO1, province);
	DDX_Control(pDX, IDC_COMBO2, city);
	//  DDX_Control(pDX, IDC_CHECK1, exercise);
	//  DDX_Control(pDX, IDC_CHECK2, game);
	//  DDX_Control(pDX, IDC_CHECK3, music);
	//  DDX_Control(pDX, IDC_CHECK4, read);
	//  DDX_Control(pDX, IDC_CHECK5, movie);
	//  DDX_Control(pDX, IDC_CHECK6, travel);
	DDX_Text(pDX, IDC_EDIT4, others);
	DDX_Check(pDX, IDC_CHECK1, exercise);
	DDX_Check(pDX, IDC_CHECK2, game);
	DDX_Check(pDX, IDC_CHECK3, music);
	//  DDX_Control(pDX, IDC_CHECK4, read);
	DDX_Check(pDX, IDC_CHECK5, movie);
	DDX_Check(pDX, IDC_CHECK6, travel);
	DDX_Check(pDX, IDC_CHECK4, read);
}

BEGIN_MESSAGE_MAP(CEx3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CEx3Dlg::OnBnClickedButton1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &CEx3Dlg::OnCbnDropdownCombo2)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx3Dlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CEx3Dlg::OnCbnSelchangeCombo2)
	ON_CBN_EDITUPDATE(IDC_COMBO1, &CEx3Dlg::OnCbnEditupdateCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CEx3Dlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CEx3Dlg ��Ϣ�������

BOOL CEx3Dlg::OnInitDialog()
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

void CEx3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx3Dlg::OnPaint()
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
HCURSOR CEx3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEx3Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	//ShowInformation showDlg(this);
	CShow dlg;
	CString province_s, city_s;
	CString& s(dlg.showStr);
	//CString s;
	province.GetLBText(province.GetCurSel(), province_s);
	city.GetLBText(city.GetCurSel(), city_s);
	/*if (!others.IsEmpty())
	{
		CStringA t(others);
		others.Format(TEXT("\n����˵�Ļ��У�%s"), t.GetBuffer());
	}*/
	//CStringA t_name(name), t_province(province_s), t_city(city_s), t_email(email), t_other(others);
	if (exercise || game || music || read || movie || travel)
		s = name + (sex ? TEXT("��Ů��") : TEXT("���У�")) + province_s + city_s + TEXT("��Ҳ��\n������Ȥ�У�") + (exercise ? TEXT("�˶���") : TEXT("")) + (game ? TEXT("��Ϸ��") : TEXT("")) + (music ? TEXT("���֣�") : TEXT("")) + (read ? TEXT("���飻") : TEXT("")) + (movie ? TEXT("��Ӱ��") : TEXT("")) + (travel ? TEXT("���Σ�") : TEXT("")) + TEXT("\n���ĵ�ַ��") + email + (others.IsEmpty() ? TEXT("") : TEXT("\n����˵�Ļ��У�")) + others;
		//s.Format(TEXT("%s��%s��%s%s��Ҳ��\n������Ȥ��%s%s%s%s%s%s\n���ĵ�ַ��%s%s"), t_name.GetBuffer(), sex ? TEXT("��") : TEXT("Ů"), t_province.GetBuffer(), t_city.GetBuffer(), exercise ? TEXT("�˶���") : TEXT(""), game ? TEXT("��Ϸ��") : TEXT(""), music ? TEXT("���֣�") : TEXT(""), read ? TEXT("���飻") : TEXT(""), movie ? TEXT("��Ӱ��") : TEXT(""), travel ? TEXT("���Σ�") : TEXT(""), t_email.GetBuffer(), t_other.GetBuffer());
	else
		s = name + (sex ? TEXT("��Ů��") : TEXT("���У�")) + province_s + city_s + TEXT("��Ҳ��\n���ĵ�ַ��") + email + (others.IsEmpty() ? TEXT("") : TEXT("\n����˵�Ļ��У�")) + others;
		//s.Format(TEXT("%s��%s��%s%s��Ҳ��\n���ĵ�ַ��%s%s"), t_name.GetBuffer(), sex ? TEXT("��") : TEXT("Ů"), t_province.GetBuffer(), t_city.GetBuffer(), t_email.GetBuffer(), t_other.GetBuffer());
	//MessageBox(s);
	//dlg.UpdateData(FALSE);
	dlg.DoModal();
	//CShow dlg(s);
	//dlg.showWidget.SetWindowTextW(s);
	//dlg.DoModal();
}


void CEx3Dlg::OnCbnDropdownCombo2()
{
	switch (province.GetCurSel())
	{
	case 0:
		city.AddString(TEXT("ʯ��ׯ"));
		city.AddString(TEXT("��ɽ"));
		city.AddString(TEXT("����"));
		city.AddString(TEXT("�ػʵ�"));
		city.AddString(TEXT("����"));
		city.AddString(TEXT("�żҿ�"));
		city.AddString(TEXT("�е�"));
		city.AddString(TEXT("�ȷ�"));
		city.AddString(TEXT("����"));
		city.AddString(TEXT("��ˮ"));
		city.AddString(TEXT("��̨"));
		break;
	case 1:
		city.AddString(TEXT("̫ԭ")); city.AddString(TEXT("��ͬ")); city.AddString(TEXT("��ͬ")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("˷��")); city.AddString(TEXT("����")); city.AddString(TEXT("�˳�")); city.AddString(TEXT("����")); city.AddString(TEXT("�ٷ�")); city.AddString(TEXT("����"));
		break;
	case 2:
		city.AddString(TEXT("������")); city.AddString(TEXT("�������")); city.AddString(TEXT("ĵ����")); city.AddString(TEXT("��ľ˹")); city.AddString(TEXT("��̨��")); city.AddString(TEXT("����")); city.AddString(TEXT("�ں�")); city.AddString(TEXT("�绯")); city.AddString(TEXT("����")); city.AddString(TEXT("�׸�")); city.AddString(TEXT("˫Ѽɽ")); city.AddString(TEXT("����"));
		break;
	case 3:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ƽ")); city.AddString(TEXT("��Դ")); city.AddString(TEXT("ͨ��")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("��ԭ")); city.AddString(TEXT("�׳�"));
		break;
	case 4:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("��˳")); city.AddString(TEXT("��Ϫ")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("Ӫ��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�̽�")); city.AddString(TEXT("����")); city.AddString(TEXT("��«��")); city.AddString(TEXT("����"));
		break;
	case 5:
		city.AddString(TEXT("�Ͼ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��")); city.AddString(TEXT("����")); city.AddString(TEXT("̩��")); city.AddString(TEXT("��ͨ")); city.AddString(TEXT("����")); city.AddString(TEXT("���Ƹ�")); city.AddString(TEXT("�γ�")); city.AddString(TEXT("����")); city.AddString(TEXT("��Ǩ"));
		break;
	case 6:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("����")); city.AddString(TEXT("��")); city.AddString(TEXT("̨��")); city.AddString(TEXT("��ˮ")); city.AddString(TEXT("����"));
		break;
	case 7:
		city.AddString(TEXT("�Ϸ�")); city.AddString(TEXT("�ߺ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("����")); city.AddString(TEXT("ͭ��")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 8:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("Ȫ��")); city.AddString(TEXT("����")); city.AddString(TEXT("��ƽ"));
		break;
	case 9:
		city.AddString(TEXT("�ϲ�")); city.AddString(TEXT("�Ž�")); city.AddString(TEXT("Ƽ��")); city.AddString(TEXT("ӥ̶")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�˴�")); city.AddString(TEXT("������")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 10:
		city.AddString(TEXT("����")); city.AddString(TEXT("�ൺ")); city.AddString(TEXT("�Ͳ�")); city.AddString(TEXT("��ׯ")); city.AddString(TEXT("��Ӫ")); city.AddString(TEXT("��̨")); city.AddString(TEXT("Ϋ��")); city.AddString(TEXT("����")); city.AddString(TEXT("̩��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�ĳ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 11:
		city.AddString(TEXT("֣��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("ƽ��ɽ")); city.AddString(TEXT("����")); city.AddString(TEXT("�ױ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("���")); city.AddString(TEXT("���")); city.AddString(TEXT("���")); city.AddString(TEXT("����Ͽ")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�ܿ�")); city.AddString(TEXT("פ���")); city.AddString(TEXT("��Դ��"));
		break;
	case 12:
		city.AddString(TEXT("�人")); city.AddString(TEXT("��ʯ")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�˲�")); city.AddString(TEXT("ʮ��")); city.AddString(TEXT("Т��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�Ƹ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ʩ����������������"));
		break;
	case 13:
		city.AddString(TEXT("��ɳ")); city.AddString(TEXT("����")); city.AddString(TEXT("��̶")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("�żҽ�")); city.AddString(TEXT("����")); city.AddString(TEXT("¦��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 14:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("��ݸ")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("�麣")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ͷ")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��β")); city.AddString(TEXT("տ��")); city.AddString(TEXT("ï��")); city.AddString(TEXT("����")); city.AddString(TEXT("�ع�")); city.AddString(TEXT("��Զ")); city.AddString(TEXT("�Ƹ�")); city.AddString(TEXT("÷��")); city.AddString(TEXT("��Դ"));
		break;
	case 15:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɳ")); city.AddString(TEXT("����"));
		break;
	case 16:
		city.AddString(TEXT("�ɶ�")); city.AddString(TEXT("�Թ�")); city.AddString(TEXT("��֦��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��Ԫ")); city.AddString(TEXT("����")); city.AddString(TEXT("�ڽ�")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("�ϳ�")); city.AddString(TEXT("üɽ")); city.AddString(TEXT("�˱�")); city.AddString(TEXT("�㰲")); city.AddString(TEXT("����")); city.AddString(TEXT("�Ű�")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 17:
		city.AddString(TEXT("����")); city.AddString(TEXT("����ˮ")); city.AddString(TEXT("����")); city.AddString(TEXT("��˳")); city.AddString(TEXT("ͭ��")); city.AddString(TEXT("�Ͻ�")); city.AddString(TEXT("ǭ���ϲ���������������")); city.AddString(TEXT("ǭ�������嶱��������")); city.AddString(TEXT("ǭ�ϲ���������������"));
		break;
	case 18:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��Ϫ")); city.AddString(TEXT("����")); city.AddString(TEXT("�ն�")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("��ͨ")); city.AddString(TEXT("�ٲ�"));
		break;
	case 19:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT(" ������ �� ͭ��")); city.AddString(TEXT("μ��")); city.AddString(TEXT(" �Ӱ��� ������")); city.AddString(TEXT(" ������ ������")); city.AddString(TEXT("����"));
		break;
	case 20:
		city.AddString(TEXT("����")); city.AddString(TEXT("������")); city.AddString(TEXT("���")); city.AddString(TEXT("����")); city.AddString(TEXT("��ˮ")); city.AddString(TEXT("����")); city.AddString(TEXT("��Ҵ")); city.AddString(TEXT("��Ȫ")); city.AddString(TEXT("ƽ��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("¤��"));
		break;
	case 21:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 22:
		city.AddString(TEXT("̨��")); city.AddString(TEXT("����")); city.AddString(TEXT("�±�")); city.AddString(TEXT("̨��")); city.AddString(TEXT("̨��")); city.AddString(TEXT("��԰"));
		break;
	case 23:
		city.AddString(TEXT("���ͺ���")); city.AddString(TEXT("��ͷ")); city.AddString(TEXT("�ں�")); city.AddString(TEXT("���")); city.AddString(TEXT("ͨ��")); city.AddString(TEXT("������˹")); city.AddString(TEXT("���ױ���")); city.AddString(TEXT("�����׶�")); city.AddString(TEXT("�����첼")); city.AddString(TEXT("�˰���")); city.AddString(TEXT("���ֹ�����")); city.AddString(TEXT("��������"));
		break;
	case 24:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("���Ǹ�")); city.AddString(TEXT("����")); city.AddString(TEXT("���")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɫ")); city.AddString(TEXT("����")); city.AddString(TEXT("�ӳ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 25:
		city.AddString(TEXT("����")); city.AddString(TEXT("�տ������")); city.AddString(TEXT("ɽ�ϵ���")); city.AddString(TEXT("��֥����")); city.AddString(TEXT("��������")); city.AddString(TEXT("��������")); city.AddString(TEXT("�������"));
		break;
	case 26:
		city.AddString(TEXT("����")); city.AddString(TEXT("ʯ��ɽ")); city.AddString(TEXT("����")); city.AddString(TEXT("��ԭ")); city.AddString(TEXT("����"));
		break;
	case 27:
		city.AddString(TEXT("��³ľ��")); city.AddString(TEXT("��������")); city.AddString(TEXT("��³��")); city.AddString(TEXT("����")); city.AddString(TEXT("��������������")); city.AddString(TEXT("���������ɹ�������")); city.AddString(TEXT("���������ɹ�������")); city.AddString(TEXT("������")); city.AddString(TEXT("�������տ¶�����������")); city.AddString(TEXT("��ʲ")); city.AddString(TEXT("����")); city.AddString(TEXT("���������������"));
		break;
	case 28:
		city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��̨")); city.AddString(TEXT("ʯ��ɽ")); city.AddString(TEXT("����")); city.AddString(TEXT("˳��")); city.AddString(TEXT("ͨ��")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("��ͷ��")); city.AddString(TEXT("��ƽ")); city.AddString(TEXT("ƽ��")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 29:
		city.AddString(TEXT("��������")); city.AddString(TEXT("��ƽ��")); city.AddString(TEXT("�Ӷ���")); city.AddString(TEXT("������")); city.AddString(TEXT("�Ͽ���")); city.AddString(TEXT("�ӱ���")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������"));
		break;
	case 30:
		city.AddString(TEXT("����")); city.AddString(TEXT("�����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("���")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("�ζ�")); city.AddString(TEXT("�ֶ�����")); city.AddString(TEXT("��ɽ")); city.AddString(TEXT("�ɽ�")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("����"));
		break;
	case 31:
		city.AddString(TEXT("������")); city.AddString(TEXT("ǭ����")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("��ɿ���")); city.AddString(TEXT("������")); city.AddString(TEXT("ɳƺ����")); city.AddString(TEXT("��������")); city.AddString(TEXT("�ϰ���")); city.AddString(TEXT("������")); city.AddString(TEXT("�山��")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("�ϴ���")); city.AddString(TEXT("������")); city.AddString(TEXT("�ϴ���")); city.AddString(TEXT("�뽭��")); city.AddString(TEXT("������")); city.AddString(TEXT("�ɽ��")); city.AddString(TEXT("ͭ����")); city.AddString(TEXT("������")); city.AddString(TEXT("�ٲ���")); city.AddString(TEXT("������")); city.AddString(TEXT("��ƽ��")); city.AddString(TEXT("��¡��"));
		break;
	case 32:
		city.AddString(TEXT("������")); city.AddString(TEXT("����")); city.AddString(TEXT("����")); city.AddString(TEXT("������")); city.AddString(TEXT("��������")); city.AddString(TEXT("������")); city.AddString(TEXT("��ˮ����")); city.AddString(TEXT("�ƴ�����")); city.AddString(TEXT("�ͼ�����")); city.AddString(TEXT("�뵺��")); city.AddString(TEXT("������")); city.AddString(TEXT("����")); city.AddString(TEXT("������")); city.AddString(TEXT("ɳ����")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("������")); city.AddString(TEXT("Ԫ����"));
		break;
	case 33:
		city.AddString(TEXT("����������")); city.AddString(TEXT("ʥ����������")); city.AddString(TEXT("������")); city.AddString(TEXT("��������")); city.AddString(TEXT("��˳����")); city.AddString(TEXT("��ģ����")); city.AddString(TEXT("ʥ���ø�����")); city.AddString(TEXT("·���"));
	}
}


void CEx3Dlg::OnBnClickedButton2()
{
	OnCancel();
}


void CEx3Dlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CEx3Dlg::OnCbnSelchangeCombo2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CEx3Dlg::OnCbnEditupdateCombo1()
{
	
}


void CEx3Dlg::OnCbnSelchangeCombo1()
{
	city.ResetContent();
}
