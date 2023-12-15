// InputDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SuchanWar.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg ��ȭ �����Դϴ�.

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


// CInputDlg �޽��� ó�����Դϴ�.


void CInputDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	CDialog::OnOK();
}


BOOL CInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	strAddressOK = _T("10.100.203.29");
	bChacked = true;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
