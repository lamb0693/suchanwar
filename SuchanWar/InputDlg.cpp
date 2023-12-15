// InputDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SuchanWar.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInputDlg, CDialog)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_INPUT_ADDRESS, pParent)
	, strAddress(_T(""))
	, strAddressOK(_T(""))
	, bChacked(FALSE)
	, bCheckedBg(FALSE)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, strAddressOK);
	DDX_Check(pDX, IDC_CHECK_SOUND, bChacked);
	DDX_Control(pDX, IDC_CHECK_BG, bBgChecked);
	DDX_Check(pDX, IDC_CHECK_BG, bCheckedBg);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CInputDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CInputDlg 메시지 처리기입니다.


void CInputDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	CDialog::OnOK();
}


BOOL CInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	strAddressOK = _T("10.100.203.29");
	bChacked = true;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
