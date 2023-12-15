#pragma once
#include "afxwin.h"


// CInputDlg 대화 상자입니다.

class CInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInputDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT_ADDRESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
