
// Ex3Dlg.cpp : 实现文件
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


// CEx3Dlg 对话框



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


// CEx3Dlg 消息处理程序

BOOL CEx3Dlg::OnInitDialog()
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEx3Dlg::OnPaint()
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
		others.Format(TEXT("\n您想说的话有：%s"), t.GetBuffer());
	}*/
	//CStringA t_name(name), t_province(province_s), t_city(city_s), t_email(email), t_other(others);
	if (exercise || game || music || read || movie || travel)
		s = name + (sex ? TEXT("，女，") : TEXT("，男，")) + province_s + city_s + TEXT("人也。\n您的兴趣有：") + (exercise ? TEXT("运动；") : TEXT("")) + (game ? TEXT("游戏；") : TEXT("")) + (music ? TEXT("音乐；") : TEXT("")) + (read ? TEXT("读书；") : TEXT("")) + (movie ? TEXT("电影；") : TEXT("")) + (travel ? TEXT("旅游；") : TEXT("")) + TEXT("\n您的地址：") + email + (others.IsEmpty() ? TEXT("") : TEXT("\n您想说的话有：")) + others;
		//s.Format(TEXT("%s，%s，%s%s人也。\n您的兴趣有%s%s%s%s%s%s\n您的地址：%s%s"), t_name.GetBuffer(), sex ? TEXT("男") : TEXT("女"), t_province.GetBuffer(), t_city.GetBuffer(), exercise ? TEXT("运动；") : TEXT(""), game ? TEXT("游戏；") : TEXT(""), music ? TEXT("音乐；") : TEXT(""), read ? TEXT("读书；") : TEXT(""), movie ? TEXT("电影；") : TEXT(""), travel ? TEXT("旅游；") : TEXT(""), t_email.GetBuffer(), t_other.GetBuffer());
	else
		s = name + (sex ? TEXT("，女，") : TEXT("，男，")) + province_s + city_s + TEXT("人也。\n您的地址：") + email + (others.IsEmpty() ? TEXT("") : TEXT("\n您想说的话有：")) + others;
		//s.Format(TEXT("%s，%s，%s%s人也。\n您的地址：%s%s"), t_name.GetBuffer(), sex ? TEXT("男") : TEXT("女"), t_province.GetBuffer(), t_city.GetBuffer(), t_email.GetBuffer(), t_other.GetBuffer());
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
		city.AddString(TEXT("石家庄"));
		city.AddString(TEXT("唐山"));
		city.AddString(TEXT("邯郸"));
		city.AddString(TEXT("秦皇岛"));
		city.AddString(TEXT("保定"));
		city.AddString(TEXT("张家口"));
		city.AddString(TEXT("承德"));
		city.AddString(TEXT("廊坊"));
		city.AddString(TEXT("沧州"));
		city.AddString(TEXT("衡水"));
		city.AddString(TEXT("邢台"));
		break;
	case 1:
		city.AddString(TEXT("太原")); city.AddString(TEXT("大同")); city.AddString(TEXT("阳同")); city.AddString(TEXT("长治")); city.AddString(TEXT("晋城")); city.AddString(TEXT("朔州")); city.AddString(TEXT("晋中")); city.AddString(TEXT("运城")); city.AddString(TEXT("忻州")); city.AddString(TEXT("临汾")); city.AddString(TEXT("吕梁"));
		break;
	case 2:
		city.AddString(TEXT("哈尔滨")); city.AddString(TEXT("齐齐哈尔")); city.AddString(TEXT("牡丹江")); city.AddString(TEXT("佳木斯")); city.AddString(TEXT("七台河")); city.AddString(TEXT("大庆")); city.AddString(TEXT("黑河")); city.AddString(TEXT("绥化")); city.AddString(TEXT("伊春")); city.AddString(TEXT("鹤岗")); city.AddString(TEXT("双鸭山")); city.AddString(TEXT("鸡西"));
		break;
	case 3:
		city.AddString(TEXT("长春")); city.AddString(TEXT("吉林")); city.AddString(TEXT("四平")); city.AddString(TEXT("辽源")); city.AddString(TEXT("通化")); city.AddString(TEXT("白山")); city.AddString(TEXT("松原")); city.AddString(TEXT("白城"));
		break;
	case 4:
		city.AddString(TEXT("沈阳")); city.AddString(TEXT("大连")); city.AddString(TEXT("鞍山")); city.AddString(TEXT("抚顺")); city.AddString(TEXT("本溪")); city.AddString(TEXT("丹东")); city.AddString(TEXT("锦州")); city.AddString(TEXT("营口")); city.AddString(TEXT("阜新")); city.AddString(TEXT("辽阳")); city.AddString(TEXT("盘锦")); city.AddString(TEXT("铁岭")); city.AddString(TEXT("葫芦岛")); city.AddString(TEXT("朝阳"));
		break;
	case 5:
		city.AddString(TEXT("南京")); city.AddString(TEXT("苏州")); city.AddString(TEXT("无锡")); city.AddString(TEXT("常州")); city.AddString(TEXT("镇江")); city.AddString(TEXT("扬州")); city.AddString(TEXT("泰州")); city.AddString(TEXT("南通")); city.AddString(TEXT("淮安")); city.AddString(TEXT("连云港")); city.AddString(TEXT("盐城")); city.AddString(TEXT("徐州")); city.AddString(TEXT("宿迁"));
		break;
	case 6:
		city.AddString(TEXT("杭州")); city.AddString(TEXT("湖州")); city.AddString(TEXT("嘉兴")); city.AddString(TEXT("绍兴")); city.AddString(TEXT("宁波")); city.AddString(TEXT("舟山")); city.AddString(TEXT("衢州")); city.AddString(TEXT("金华")); city.AddString(TEXT("台州")); city.AddString(TEXT("丽水")); city.AddString(TEXT("温州"));
		break;
	case 7:
		city.AddString(TEXT("合肥")); city.AddString(TEXT("芜湖")); city.AddString(TEXT("蚌埠")); city.AddString(TEXT("淮南")); city.AddString(TEXT("马鞍山")); city.AddString(TEXT("淮北")); city.AddString(TEXT("铜陵")); city.AddString(TEXT("安庆")); city.AddString(TEXT("黄山")); city.AddString(TEXT("阜阳")); city.AddString(TEXT("宿州")); city.AddString(TEXT("滁州")); city.AddString(TEXT("六安")); city.AddString(TEXT("宣城")); city.AddString(TEXT("池州")); city.AddString(TEXT("亳州"));
		break;
	case 8:
		city.AddString(TEXT("福州")); city.AddString(TEXT("厦门")); city.AddString(TEXT("莆田")); city.AddString(TEXT("龙岩")); city.AddString(TEXT("漳州")); city.AddString(TEXT("三明")); city.AddString(TEXT("泉州")); city.AddString(TEXT("宁德")); city.AddString(TEXT("南平"));
		break;
	case 9:
		city.AddString(TEXT("南昌")); city.AddString(TEXT("九江")); city.AddString(TEXT("萍乡")); city.AddString(TEXT("鹰潭")); city.AddString(TEXT("上饶")); city.AddString(TEXT("抚州")); city.AddString(TEXT("新余")); city.AddString(TEXT("宜春")); city.AddString(TEXT("景德镇")); city.AddString(TEXT("吉安")); city.AddString(TEXT("赣州"));
		break;
	case 10:
		city.AddString(TEXT("济南")); city.AddString(TEXT("青岛")); city.AddString(TEXT("淄博")); city.AddString(TEXT("枣庄")); city.AddString(TEXT("东营")); city.AddString(TEXT("烟台")); city.AddString(TEXT("潍坊")); city.AddString(TEXT("济宁")); city.AddString(TEXT("泰安")); city.AddString(TEXT("威海")); city.AddString(TEXT("日照")); city.AddString(TEXT("莱芜")); city.AddString(TEXT("临沂")); city.AddString(TEXT("德州")); city.AddString(TEXT("聊城")); city.AddString(TEXT("滨州")); city.AddString(TEXT("菏泽"));
		break;
	case 11:
		city.AddString(TEXT("郑州")); city.AddString(TEXT("开封")); city.AddString(TEXT("洛阳")); city.AddString(TEXT("平顶山")); city.AddString(TEXT("焦作")); city.AddString(TEXT("鹤壁")); city.AddString(TEXT("新乡")); city.AddString(TEXT("安阳")); city.AddString(TEXT("濮阳")); city.AddString(TEXT("许昌")); city.AddString(TEXT("漯河")); city.AddString(TEXT("三门峡")); city.AddString(TEXT("南阳")); city.AddString(TEXT("商丘")); city.AddString(TEXT("信阳")); city.AddString(TEXT("周口")); city.AddString(TEXT("驻马店")); city.AddString(TEXT("济源市"));
		break;
	case 12:
		city.AddString(TEXT("武汉")); city.AddString(TEXT("黄石")); city.AddString(TEXT("襄阳")); city.AddString(TEXT("荆州")); city.AddString(TEXT("宜昌")); city.AddString(TEXT("十堰")); city.AddString(TEXT("孝感")); city.AddString(TEXT("荆门")); city.AddString(TEXT("鄂州")); city.AddString(TEXT("黄冈")); city.AddString(TEXT("咸宁")); city.AddString(TEXT("随州")); city.AddString(TEXT("恩施土家族苗族自治州"));
		break;
	case 13:
		city.AddString(TEXT("长沙")); city.AddString(TEXT("株洲")); city.AddString(TEXT("湘潭")); city.AddString(TEXT("衡阳")); city.AddString(TEXT("邵阳")); city.AddString(TEXT("岳阳")); city.AddString(TEXT("常德")); city.AddString(TEXT("张家界")); city.AddString(TEXT("益阳")); city.AddString(TEXT("娄底")); city.AddString(TEXT("郴州")); city.AddString(TEXT("永州")); city.AddString(TEXT("怀化"));
		break;
	case 14:
		city.AddString(TEXT("广州")); city.AddString(TEXT("深圳")); city.AddString(TEXT("佛山")); city.AddString(TEXT("东莞")); city.AddString(TEXT("中山")); city.AddString(TEXT("珠海")); city.AddString(TEXT("江门")); city.AddString(TEXT("肇庆")); city.AddString(TEXT("惠州")); city.AddString(TEXT("汕头")); city.AddString(TEXT("潮州")); city.AddString(TEXT("揭阳")); city.AddString(TEXT("汕尾")); city.AddString(TEXT("湛江")); city.AddString(TEXT("茂名")); city.AddString(TEXT("阳江")); city.AddString(TEXT("韶关")); city.AddString(TEXT("清远")); city.AddString(TEXT("云浮")); city.AddString(TEXT("梅州")); city.AddString(TEXT("河源"));
		break;
	case 15:
		city.AddString(TEXT("海口")); city.AddString(TEXT("三亚")); city.AddString(TEXT("三沙")); city.AddString(TEXT("儋州"));
		break;
	case 16:
		city.AddString(TEXT("成都")); city.AddString(TEXT("自贡")); city.AddString(TEXT("攀枝花")); city.AddString(TEXT("泸州")); city.AddString(TEXT("德阳")); city.AddString(TEXT("绵阳")); city.AddString(TEXT("广元")); city.AddString(TEXT("遂宁")); city.AddString(TEXT("内江")); city.AddString(TEXT("乐山")); city.AddString(TEXT("南充")); city.AddString(TEXT("眉山")); city.AddString(TEXT("宜宾")); city.AddString(TEXT("广安")); city.AddString(TEXT("达州")); city.AddString(TEXT("雅安")); city.AddString(TEXT("巴中")); city.AddString(TEXT("资阳"));
		break;
	case 17:
		city.AddString(TEXT("贵阳")); city.AddString(TEXT("六盘水")); city.AddString(TEXT("遵义")); city.AddString(TEXT("安顺")); city.AddString(TEXT("铜仁")); city.AddString(TEXT("毕节")); city.AddString(TEXT("黔西南布依族苗族自治州")); city.AddString(TEXT("黔东南苗族侗族自治州")); city.AddString(TEXT("黔南布依族苗族自治州"));
		break;
	case 18:
		city.AddString(TEXT("昆明")); city.AddString(TEXT("曲靖")); city.AddString(TEXT("玉溪")); city.AddString(TEXT("丽江")); city.AddString(TEXT("普洱")); city.AddString(TEXT("保山")); city.AddString(TEXT("昭通")); city.AddString(TEXT("临沧"));
		break;
	case 19:
		city.AddString(TEXT("西安")); city.AddString(TEXT("宝鸡")); city.AddString(TEXT(" 咸阳市 、 铜川")); city.AddString(TEXT("渭南")); city.AddString(TEXT(" 延安市 、榆林")); city.AddString(TEXT(" 汉中市 、安康")); city.AddString(TEXT("商洛"));
		break;
	case 20:
		city.AddString(TEXT("兰州")); city.AddString(TEXT("嘉峪关")); city.AddString(TEXT("金昌")); city.AddString(TEXT("白银")); city.AddString(TEXT("天水")); city.AddString(TEXT("武威")); city.AddString(TEXT("张掖")); city.AddString(TEXT("酒泉")); city.AddString(TEXT("平凉")); city.AddString(TEXT("庆阳")); city.AddString(TEXT("定西")); city.AddString(TEXT("陇南"));
		break;
	case 21:
		city.AddString(TEXT("西宁")); city.AddString(TEXT("海东")); city.AddString(TEXT("海北")); city.AddString(TEXT("海南")); city.AddString(TEXT("海西")); city.AddString(TEXT("黄南")); city.AddString(TEXT("果洛"));
		break;
	case 22:
		city.AddString(TEXT("台北")); city.AddString(TEXT("高雄")); city.AddString(TEXT("新北")); city.AddString(TEXT("台中")); city.AddString(TEXT("台南")); city.AddString(TEXT("桃园"));
		break;
	case 23:
		city.AddString(TEXT("呼和浩特")); city.AddString(TEXT("包头")); city.AddString(TEXT("乌海")); city.AddString(TEXT("赤峰")); city.AddString(TEXT("通辽")); city.AddString(TEXT("鄂尔多斯")); city.AddString(TEXT("呼伦贝尔")); city.AddString(TEXT("巴彦淖尔")); city.AddString(TEXT("乌兰察布")); city.AddString(TEXT("兴安盟")); city.AddString(TEXT("锡林郭勒盟")); city.AddString(TEXT("阿拉善盟"));
		break;
	case 24:
		city.AddString(TEXT("南宁")); city.AddString(TEXT("柳州")); city.AddString(TEXT("桂林")); city.AddString(TEXT("梧州")); city.AddString(TEXT("北海")); city.AddString(TEXT("防城港")); city.AddString(TEXT("钦州")); city.AddString(TEXT("贵港")); city.AddString(TEXT("玉林")); city.AddString(TEXT("百色")); city.AddString(TEXT("贺州")); city.AddString(TEXT("河池")); city.AddString(TEXT("来宾")); city.AddString(TEXT("崇左"));
		break;
	case 25:
		city.AddString(TEXT("拉萨")); city.AddString(TEXT("日喀则地区")); city.AddString(TEXT("山南地区")); city.AddString(TEXT("林芝地区")); city.AddString(TEXT("昌都地区")); city.AddString(TEXT("那曲地区")); city.AddString(TEXT("阿里地区"));
		break;
	case 26:
		city.AddString(TEXT("银川")); city.AddString(TEXT("石嘴山")); city.AddString(TEXT("吴忠")); city.AddString(TEXT("固原")); city.AddString(TEXT("中卫"));
		break;
	case 27:
		city.AddString(TEXT("乌鲁木齐")); city.AddString(TEXT("克拉玛依")); city.AddString(TEXT("吐鲁番")); city.AddString(TEXT("哈密")); city.AddString(TEXT("昌吉回族自治州")); city.AddString(TEXT("博尔塔拉蒙古自治州")); city.AddString(TEXT("巴音郭楞蒙古自治州")); city.AddString(TEXT("阿克苏")); city.AddString(TEXT("克孜勒苏柯尔克孜自治州")); city.AddString(TEXT("喀什")); city.AddString(TEXT("和田")); city.AddString(TEXT("伊犁哈萨克自治州"));
		break;
	case 28:
		city.AddString(TEXT("东城")); city.AddString(TEXT("西城")); city.AddString(TEXT("朝阳")); city.AddString(TEXT("丰台")); city.AddString(TEXT("石景山")); city.AddString(TEXT("海淀")); city.AddString(TEXT("顺义")); city.AddString(TEXT("通州")); city.AddString(TEXT("大兴")); city.AddString(TEXT("房山")); city.AddString(TEXT("门头沟")); city.AddString(TEXT("昌平")); city.AddString(TEXT("平谷")); city.AddString(TEXT("密云")); city.AddString(TEXT("怀柔")); city.AddString(TEXT("延庆"));
		break;
	case 29:
		city.AddString(TEXT("滨海新区")); city.AddString(TEXT("和平区")); city.AddString(TEXT("河东区")); city.AddString(TEXT("河西区")); city.AddString(TEXT("南开区")); city.AddString(TEXT("河北区")); city.AddString(TEXT("红桥区")); city.AddString(TEXT("东丽区")); city.AddString(TEXT("西青区")); city.AddString(TEXT("津南区")); city.AddString(TEXT("北辰区")); city.AddString(TEXT("武清区")); city.AddString(TEXT("宝坻区")); city.AddString(TEXT("静海区")); city.AddString(TEXT("宁河区")); city.AddString(TEXT("蓟州区"));
		break;
	case 30:
		city.AddString(TEXT("黄浦")); city.AddString(TEXT("徐汇区")); city.AddString(TEXT("长宁")); city.AddString(TEXT("静安")); city.AddString(TEXT("普陀")); city.AddString(TEXT("虹口")); city.AddString(TEXT("杨浦")); city.AddString(TEXT("闵行")); city.AddString(TEXT("宝山")); city.AddString(TEXT("嘉定")); city.AddString(TEXT("浦东新区")); city.AddString(TEXT("金山")); city.AddString(TEXT("松江")); city.AddString(TEXT("青浦")); city.AddString(TEXT("奉贤")); city.AddString(TEXT("崇明"));
		break;
	case 31:
		city.AddString(TEXT("万州区")); city.AddString(TEXT("黔江区")); city.AddString(TEXT("涪陵区")); city.AddString(TEXT("渝中区")); city.AddString(TEXT("大渡口区")); city.AddString(TEXT("江北区")); city.AddString(TEXT("沙坪坝区")); city.AddString(TEXT("九龙坡区")); city.AddString(TEXT("南岸区")); city.AddString(TEXT("北碚区")); city.AddString(TEXT("渝北区")); city.AddString(TEXT("巴南区")); city.AddString(TEXT("长寿区")); city.AddString(TEXT("江津区")); city.AddString(TEXT("合川区")); city.AddString(TEXT("永川区")); city.AddString(TEXT("南川区")); city.AddString(TEXT("綦江区")); city.AddString(TEXT("大足区")); city.AddString(TEXT("璧山区")); city.AddString(TEXT("铜梁区")); city.AddString(TEXT("潼南区")); city.AddString(TEXT("荣昌区")); city.AddString(TEXT("开州区")); city.AddString(TEXT("梁平区")); city.AddString(TEXT("武隆区"));
		break;
	case 32:
		city.AddString(TEXT("中西区")); city.AddString(TEXT("东区")); city.AddString(TEXT("南区")); city.AddString(TEXT("湾仔区")); city.AddString(TEXT("九龙城区")); city.AddString(TEXT("观塘区")); city.AddString(TEXT("深水埗区")); city.AddString(TEXT("黄大仙区")); city.AddString(TEXT("油尖旺区")); city.AddString(TEXT("离岛区")); city.AddString(TEXT("葵青区")); city.AddString(TEXT("北区")); city.AddString(TEXT("西贡区")); city.AddString(TEXT("沙田区")); city.AddString(TEXT("大埔区")); city.AddString(TEXT("荃湾区")); city.AddString(TEXT("屯门区")); city.AddString(TEXT("元朗区"));
		break;
	case 33:
		city.AddString(TEXT("花地玛堂区")); city.AddString(TEXT("圣安多尼堂区")); city.AddString(TEXT("大堂区")); city.AddString(TEXT("望德堂区")); city.AddString(TEXT("风顺堂区")); city.AddString(TEXT("嘉模堂区")); city.AddString(TEXT("圣方济各堂区")); city.AddString(TEXT("路氹城"));
	}
}


void CEx3Dlg::OnBnClickedButton2()
{
	OnCancel();
}


void CEx3Dlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CEx3Dlg::OnCbnSelchangeCombo2()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CEx3Dlg::OnCbnEditupdateCombo1()
{
	
}


void CEx3Dlg::OnCbnSelchangeCombo1()
{
	city.ResetContent();
}
