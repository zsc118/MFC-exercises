
// Ex7Set.cpp : CEx7Set ���ʵ��
//

#include "stdafx.h"
#include "Ex7.h"
#include "Ex7Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx7Set ʵ��

// ���������� 2023��12��1��, 16:53

IMPLEMENT_DYNAMIC(CEx7Set, CRecordset)

CEx7Set::CEx7Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = 0;
	m_studentnum = L"";
	m_studentname = L"";
	m_subject = L"";
	m_mark = 0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CEx7Set::GetDefaultConnect()
{
	return _T("DSN=MFCEx7;DBQ=D:\\\x5b66\x4e60\\\x8bfe\x7a0b\\\x5e94\x7528\x4e0e\x8ba1\x7b97\x6570\x5b66\\\x8ba1\x7b97\x673a\\C++\\MFC\\\x5b9e\x8df5\\Ex7\\studentmarks.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;PWD=210329;UID=admin;");
}

CString CEx7Set::GetDefaultSQL()
{
	return _T("[studenttable]");
}

void CEx7Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[studentnum]"), m_studentnum);
	RFX_Text(pFX, _T("[studentname]"), m_studentname);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Long(pFX, _T("[mark]"), m_mark);

}
/////////////////////////////////////////////////////////////////////////////
// CEx7Set ���

#ifdef _DEBUG
void CEx7Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx7Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

