
// Ex7Set.cpp : CEx7Set 类的实现
//

#include "stdafx.h"
#include "Ex7.h"
#include "Ex7Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx7Set 实现

// 代码生成在 2023年12月1日, 16:53

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[编号]"), column1);
	RFX_Text(pFX, _T("[studentnum]"), m_studentnum);
	RFX_Text(pFX, _T("[studentname]"), m_studentname);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Long(pFX, _T("[mark]"), m_mark);

}
/////////////////////////////////////////////////////////////////////////////
// CEx7Set 诊断

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

