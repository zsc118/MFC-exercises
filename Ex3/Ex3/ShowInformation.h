#pragma once


// ShowInformation �Ի���

class ShowInformation : public CDialogEx
{
	DECLARE_DYNAMIC(ShowInformation)

public:
	ShowInformation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowInformation();

// �Ի�������
	enum { IDD = IDD_SHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CString information;
	afx_msg void OnBnClickedButton1();
	CString information;
};
