
// Ex5Dlg.h : ͷ�ļ�
//

#pragma once
#include "ClockWidget.h"

// CEx5Dlg �Ի���
class CEx5Dlg : public CDialogEx
{
// ����
public:
	CEx5Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EX5_DIALOG };

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
private:
//	CClockWidget m_clock;
	CClockWidget m_clock;
public:
	afx_msg void OnClose();
};
