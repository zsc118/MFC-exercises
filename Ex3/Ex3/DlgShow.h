#pragma once


// CDlgShow �Ի���

class CDlgShow : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShow)

public:
	CDlgShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShow();

// �Ի�������
	enum { IDD = IDD_SHOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
