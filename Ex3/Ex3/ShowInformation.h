#pragma once


// ShowInformation 对话框

class ShowInformation : public CDialogEx
{
	DECLARE_DYNAMIC(ShowInformation)

public:
	ShowInformation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowInformation();

// 对话框数据
	enum { IDD = IDD_SHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CString information;
	afx_msg void OnBnClickedButton1();
	CString information;
};
