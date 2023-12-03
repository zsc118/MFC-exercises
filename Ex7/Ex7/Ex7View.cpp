
// Ex7View.cpp : CEx7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex7.h"
#endif

#include "Ex7Set.h"
#include "Ex7Doc.h"
#include "Ex7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx7View

IMPLEMENT_DYNCREATE(CEx7View, CRecordView)

BEGIN_MESSAGE_MAP(CEx7View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx7View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx7View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CEx7View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CEx7View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CEx7View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CEx7View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &CEx7View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CEx7View::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CEx7View::OnBnClickedButton9)
END_MESSAGE_MAP()

// CEx7View 构造/析构

CEx7View::CEx7View()
	: CRecordView(CEx7View::IDD)
	, m_strQuery(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CEx7View::~CEx7View()
{
}

void CEx7View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->column1, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_studentnum, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_studentname, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_subject, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_mark, m_pSet);
	DDX_Text(pDX, IDC_EDIT6, m_strQuery);
}

BOOL CEx7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CEx7View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex7Set;
	CRecordView::OnInitialUpdate();

}


// CEx7View 打印

BOOL CEx7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEx7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CEx7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CEx7View 诊断

#ifdef _DEBUG
void CEx7View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx7View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx7Doc* CEx7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx7Doc)));
	return (CEx7Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx7View 数据库支持
CRecordset* CEx7View::OnGetRecordset()
{
	return m_pSet;
}



// CEx7View 消息处理程序

// 上一条
void CEx7View::OnBnClickedButton1()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MovePrev();
		if (m_pSet->IsBOF())
			MessageBox(TEXT("当前已经为第1条记录!"));
		else
			UpdateData(FALSE);
	}
}

// 下一条
void CEx7View::OnBnClickedButton2()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MoveNext();
		if (m_pSet->IsEOF())
			MessageBox(TEXT("当前已经为最后一条记录!"));
		else
			UpdateData(FALSE);
	}
}

// 最后一条
void CEx7View::OnBnClickedButton3()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MoveLast();
		UpdateData(FALSE);
	}
}

// 最初一条
void CEx7View::OnBnClickedButton4()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MoveFirst();
		UpdateData(FALSE);
	}
}

#define SET_FIELD_NULL                                     \
	m_pSet->SetFieldNull(&(m_pSet->column1), FALSE);       \
	m_pSet->SetFieldNull(&(m_pSet->m_studentnum), FALSE);  \
	m_pSet->SetFieldNull(&(m_pSet->m_studentname), FALSE); \
	m_pSet->SetFieldNull(&(m_pSet->m_subject), FALSE);     \
	m_pSet->SetFieldNull(&(m_pSet->m_mark), FALSE);

// 添加
void CEx7View::OnBnClickedButton5()
{
	m_pSet->AddNew();
	SET_FIELD_NULL
	UpdateData(TRUE);
	m_pSet->Update();
	m_pSet->Requery();
	MessageBox(TEXT("添加成功!"));
}

// 删除
void CEx7View::OnBnClickedButton7()
{
	if (MessageBox(TEXT("真的要删除该记录吗?"), TEXT("删除记录"), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		m_pSet->Delete();
		m_pSet->MoveNext();
		if (m_pSet->IsEOF())
			m_pSet->MoveLast();
		if (m_pSet->IsBOF())
			m_pSet->SetFieldNull(NULL);
		UpdateData(FALSE);
		MessageBox(TEXT("删除成功!"));
	}
}

// 修改
void CEx7View::OnBnClickedButton6()
{
	m_pSet->Edit();
	UpdateData(TRUE);
	m_pSet->Update();
	m_pSet->Requery();
	MessageBox(TEXT("修改成功!"));
}

// 查询
void CEx7View::OnBnClickedButton8()
{
	UpdateData(TRUE);
	m_pSet->m_strFilter = TEXT("[studentname]='") + m_strQuery + TEXT("'");
	m_pSet->Requery();
	UpdateData(FALSE);
}

// 按成绩排序
void CEx7View::OnBnClickedButton9()
{
	m_pSet->m_strSort = "mark";
	m_pSet->Requery();
	UpdateData(FALSE);
}
