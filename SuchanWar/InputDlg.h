#pragma once
#include "afxwin.h"


// CInputDlg ��ȭ �����Դϴ�.

class CInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInputDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT_ADDRESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString strAddress;
	afx_msg void OnBnClickedOk();
	CString strAddressOK;
	virtual BOOL OnInitDialog();
	BOOL bChacked;
	CButton bBgChecked;
	BOOL bCheckedBg;
};
