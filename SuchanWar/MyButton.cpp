// MyButton.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SuchanWar.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton(CWnd* pWnd, int nID)
{
	m_pWnd = pWnd;
	m_nButtonID = nID;
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CMyButton �޽��� ó�����Դϴ�.




void CMyButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_pWnd->SendMessageW(SM_BUTTONCLICK, m_nButtonID, NULL);

	CButton::OnLButtonUp(nFlags, point);
}

