
// Ex7View.h : CEx7View ��Ľӿ�
//

#pragma once

class CEx7Set;

class CEx7View : public CRecordView
{
protected: // �������л�����
	CEx7View();
	DECLARE_DYNCREATE(CEx7View)

public:
	enum{ IDD = IDD_EX7_FORM };
	CEx7Set* m_pSet;

// ����
public:
	CEx7Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CEx7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	CString m_strQuery;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};

#ifndef _DEBUG  // Ex7View.cpp �еĵ��԰汾
inline CEx7Doc* CEx7View::GetDocument() const
   { return reinterpret_cast<CEx7Doc*>(m_pDocument); }
#endif

