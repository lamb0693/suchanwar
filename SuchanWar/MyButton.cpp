// MyButton.cpp : 구현 파일입니다.
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



// CMyButton 메시지 처리기입니다.




void CMyButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pWnd->SendMessageW(SM_BUTTONCLICK, m_nButtonID, NULL);

	CButton::OnLButtonUp(nFlags, point);
}

