
// Ex7View.cpp : CEx7View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CEx7View ����/����

CEx7View::CEx7View()
	: CRecordView(CEx7View::IDD)
	, m_strQuery(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CEx7View::~CEx7View()
{
}

void CEx7View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->column1, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_studentnum, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_studentname, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_subject, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_mark, m_pSet);
	DDX_Text(pDX, IDC_EDIT6, m_strQuery);
}

BOOL CEx7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CEx7View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Ex7Set;
	CRecordView::OnInitialUpdate();

}


// CEx7View ��ӡ

BOOL CEx7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEx7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEx7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CEx7View ���

#ifdef _DEBUG
void CEx7View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx7View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx7Doc* CEx7View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx7Doc)));
	return (CEx7Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx7View ���ݿ�֧��
CRecordset* CEx7View::OnGetRecordset()
{
	return m_pSet;
}



// CEx7View ��Ϣ�������

// ��һ��
void CEx7View::OnBnClickedButton1()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MovePrev();
		if (m_pSet->IsBOF())
			MessageBox(TEXT("��ǰ�Ѿ�Ϊ��1����¼!"));
		else
			UpdateData(FALSE);
	}
}

// ��һ��
void CEx7View::OnBnClickedButton2()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MoveNext();
		if (m_pSet->IsEOF())
			MessageBox(TEXT("��ǰ�Ѿ�Ϊ���һ����¼!"));
		else
			UpdateData(FALSE);
	}
}

// ���һ��
void CEx7View::OnBnClickedButton3()
{
	if (m_pSet->IsOpen())
	{
		m_pSet->MoveLast();
		UpdateData(FALSE);
	}
}

// ���һ��
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

// ���
void CEx7View::OnBnClickedButton5()
{
	m_pSet->AddNew();
	SET_FIELD_NULL
	UpdateData(TRUE);
	m_pSet->Update();
	m_pSet->Requery();
	MessageBox(TEXT("��ӳɹ�!"));
}

// ɾ��
void CEx7View::OnBnClickedButton7()
{
	if (MessageBox(TEXT("���Ҫɾ���ü�¼��?"), TEXT("ɾ����¼"), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		m_pSet->Delete();
		m_pSet->MoveNext();
		if (m_pSet->IsEOF())
			m_pSet->MoveLast();
		if (m_pSet->IsBOF())
			m_pSet->SetFieldNull(NULL);
		UpdateData(FALSE);
		MessageBox(TEXT("ɾ���ɹ�!"));
	}
}

// �޸�
void CEx7View::OnBnClickedButton6()
{
	m_pSet->Edit();
	UpdateData(TRUE);
	m_pSet->Update();
	m_pSet->Requery();
	MessageBox(TEXT("�޸ĳɹ�!"));
}

// ��ѯ
void CEx7View::OnBnClickedButton8()
{
	UpdateData(TRUE);
	m_pSet->m_strFilter = TEXT("[studentname]='") + m_strQuery + TEXT("'");
	m_pSet->Requery();
	UpdateData(FALSE);
}

// ���ɼ�����
void CEx7View::OnBnClickedButton9()
{
	m_pSet->m_strSort = "mark";
	m_pSet->Requery();
	UpdateData(FALSE);
}
