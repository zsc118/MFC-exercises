
// Ex3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CEx3Dlg �Ի���
class CEx3Dlg : public CDialogEx
{
// ����
public:
	CEx3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EX3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	BOOL sex;
	CString email;
	CComboBox province;
	CComboBox city;
//	CButton exercise;
//	CButton game;
//	CButton music;
//	CButton read;
//	CButton movie;
//	CButton travel;
	CString others;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnDropdownCombo2();
	BOOL exercise;
	BOOL game;
	BOOL music;
//	CButton read;
	BOOL movie;
	BOOL travel;
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnEditupdateCombo1();
	afx_msg void OnCbnSelchangeCombo1();
	BOOL read;
};
