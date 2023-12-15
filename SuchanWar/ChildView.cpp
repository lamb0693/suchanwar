
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "SuchanWar.h"
#include "ChildView.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView



CChildView::CChildView() : m_team(0), m_Mana(0)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_MESSAGE(SM_RECEIVEDDATA, &CChildView::OnSmReceiveddata)
	ON_WM_KEYDOWN()
	ON_MESSAGE(SM_BUTTONCLICK, &CChildView::OnSmButtonclick)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	dc.BitBlt(0, 0, 1600, 100, m_pDC[_BANNER], 0, 0, SRCCOPY);
	dc.BitBlt(0, 100, 1600, 250, m_pDC[_BG], 0, 0, SRCCOPY);
	dc.BitBlt(0, 350, 1600, 100, m_pDC[_LOWERPANEL], 0, 0, SRCCOPY);

//	dc.Rectangle(manaRect);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CView * pView = (CView*) this;
	m_pSocket = new CConnectSocket(pView);
	m_pSocket->Create();

	CInputDlg dlg;
	CString str;
	
	dlg.DoModal();
	
	bBg2 = dlg.bCheckedBg;
	if (m_pSocket->Connect(dlg.strAddressOK, 9876) == FALSE) {
		AfxMessageBox(_T("서버 접속 실패"));
		PostQuitMessage(0);
	}

/*
	if (m_pSocket->Connect(_T("192.168.0.87"), 9876) == FALSE) {
		AfxMessageBox(_T("서버 접속 실패"));
		PostQuitMessage(0);
	}
*/	
	rectBG.SetRect(0, 100, 1600, 350);
	manaRectP1.SetRect(30, 20, 150, 80);
	manaRectP1Wnd.SetRect(30, 370, 150, 430);
	manaRectP2.SetRect(1450, 20, 1570, 80);
	manaRectP2Wnd.SetRect(1450, 370, 1570, 430);
	rectLowerPanal.SetRect(0, 350, 1600, 450);

	CDC* pDC = GetDC();
	for (int i = 0; i < NoOfDC; i++) {
		m_pBitmap[i] = new CBitmap();
		m_pDC[i] = new CDC;
		m_pDC[i]->CreateCompatibleDC(pDC);
		m_pBmpInfo[i] = new BITMAP;
	}
	m_pBitmap[_BANNER]->CreateBitmap(1600, 100, m_pDC[_BANNER]->GetDeviceCaps(PLANES), m_pDC[_BANNER]->GetDeviceCaps(BITSPIXEL), 0);
	m_pBitmap[_BG]->CreateBitmap(1600, 250, m_pDC[_BG]->GetDeviceCaps(PLANES), m_pDC[_BG]->GetDeviceCaps(BITSPIXEL), 0);
	m_pBitmap[_LOWERPANEL]->CreateBitmap(1600, 100, m_pDC[_LOWERPANEL]->GetDeviceCaps(PLANES), m_pDC[_LOWERPANEL]->GetDeviceCaps(BITSPIXEL), 0);
	m_pBitmap[_BANNERIMAGE]->LoadBitmapW(IDB_BITMAP_BANNER);
	m_pBitmap[_BGIMAGE]->LoadBitmapW(IDB_BITMAP_BG);
	m_pBitmap[_BGIMAGE2]->LoadBitmapW(IDB_BITMAP_BG_2);
	m_pBitmap[_LOWERPANELIMAGE]->LoadBitmapW(IDB_BITMAP_LOWER);
	m_pBitmap[_WARRIOR1]->LoadBitmapW(IDB_BITMAP_WARRIOR1);
	m_pBitmap[_WARRIOR2]->LoadBitmapW(IDB_BITMAP_WARRIOR2);
	m_pBitmap[_WARRIOR3]->LoadBitmapW(IDB_BITMAP_WARRIOR3);
	m_pBitmap[_WARRIOR4]->LoadBitmapW(IDB_BITMAP_WARRIOR4);
	m_pBitmap[_WARRIOR5]->LoadBitmapW(IDB_BITMAP_WARRIOR5);
	m_pBitmap[_WARRIOR6]->LoadBitmapW(IDB_BITMAP_WARRIOR6);
	m_pBitmap[_WARRIOR7]->LoadBitmapW(IDB_BITMAP_WARRIOR7);
	m_pBitmap[_WARRIOR8]->LoadBitmapW(IDB_BITMAP_WARRIOR8);
	m_pBitmap[_ARCHER1]->LoadBitmapW(IDB_BITMAP_ARCHER1);
	m_pBitmap[_ARCHER2]->LoadBitmapW(IDB_BITMAP_ARCHER2);
	m_pBitmap[_ARCHER3]->LoadBitmapW(IDB_BITMAP_ARCHER3);
	m_pBitmap[_ARCHER4]->LoadBitmapW(IDB_BITMAP_ARCHER4);
	m_pBitmap[_ARCHER5]->LoadBitmapW(IDB_BITMAP_ARCHER6);  // 5는 없다
	m_pBitmap[_ARCHER6]->LoadBitmapW(IDB_BITMAP_ARCHER7);
	m_pBitmap[_ARCHER7]->LoadBitmapW(IDB_BITMAP_ARCHER8);
	m_pBitmap[_ARCHER8]->LoadBitmapW(IDB_BITMAP_ARCHER9);
	m_pBitmap[_WIZARD1]->LoadBitmapW(IDB_BITMAP_WIZARD1);
	m_pBitmap[_WIZARD2]->LoadBitmapW(IDB_BITMAP_WIZARD2);
	m_pBitmap[_WIZARD3]->LoadBitmapW(IDB_BITMAP_WIZARD3);
	m_pBitmap[_WIZARD4]->LoadBitmapW(IDB_BITMAP_WIZARD4);
	m_pBitmap[_WIZARD5]->LoadBitmapW(IDB_BITMAP_WIZARD5);
	m_pBitmap[_WIZARD6]->LoadBitmapW(IDB_BITMAP_WIZARD6);
	m_pBitmap[_WIZARD7]->LoadBitmapW(IDB_BITMAP_WIZARD7);
	m_pBitmap[_WIZARD8]->LoadBitmapW(IDB_BITMAP_WIZARD8);
	m_pBitmap[_GOLEM1]->LoadBitmapW(IDB_BITMAP_GOLEM1);
	m_pBitmap[_GOLEM2]->LoadBitmapW(IDB_BITMAP_GOLEM2);
	m_pBitmap[_GOLEM3]->LoadBitmapW(IDB_BITMAP_GOLEM3);
	m_pBitmap[_GOLEM4]->LoadBitmapW(IDB_BITMAP_GOLEM4);	
	m_pBitmap[_GOLEM5]->LoadBitmapW(IDB_BITMAP_GOLEM5);
	m_pBitmap[_GOLEM6]->LoadBitmapW(IDB_BITMAP_GOLEM6);
	m_pBitmap[_GOLEM7]->LoadBitmapW(IDB_BITMAP_GOLEM7);
	m_pBitmap[_GOLEM8]->LoadBitmapW(IDB_BITMAP_GOLEM8);
	m_pBitmap[_DRAGON1]->LoadBitmapW(IDB_BITMAP_DRAGON1);
	m_pBitmap[_DRAGON2]->LoadBitmapW(IDB_BITMAP_DRAGON2);
	m_pBitmap[_DRAGON3]->LoadBitmapW(IDB_BITMAP_DRAGON3);
	m_pBitmap[_DRAGON4]->LoadBitmapW(IDB_BITMAP_DRAGON4);
	m_pBitmap[_DRAGON5]->LoadBitmapW(IDB_BITMAP_DRAGON5);
	m_pBitmap[_DRAGON6]->LoadBitmapW(IDB_BITMAP_DRAGON6);
	m_pBitmap[_DRAGON7]->LoadBitmapW(IDB_BITMAP_DRAGON7);
	m_pBitmap[_DRAGON8]->LoadBitmapW(IDB_BITMAP_DRAGON8);
	m_pBitmap[_SKELETON1]->LoadBitmapW(IDB_BITMAP_SKELETON1);
	m_pBitmap[_SKELETON2]->LoadBitmapW(IDB_BITMAP_SKELETON2);
	m_pBitmap[_SKELETON3]->LoadBitmapW(IDB_BITMAP_SKELETON3);
	m_pBitmap[_SKELETON4]->LoadBitmapW(IDB_BITMAP_SKELETON4);
	m_pBitmap[_SKELETON5]->LoadBitmapW(IDB_BITMAP_SKELETON5);
	m_pBitmap[_SKELETON6]->LoadBitmapW(IDB_BITMAP_SKELETON6);
	m_pBitmap[_SKELETON7]->LoadBitmapW(IDB_BITMAP_SKELETON7);
	m_pBitmap[_SKELETON8]->LoadBitmapW(IDB_BITMAP_SKELETON8);


	for (int i = 0; i < NoOfDC; i++)
	{
		m_pOldBitmap[i] = m_pDC[i]->SelectObject(m_pBitmap[i]);
		m_pBitmap[i]->GetBitmap(m_pBmpInfo[i]);
	}

	ScreenX = 0;

	if(bBg2) m_pDC[_BG]->BitBlt(0, 0, 1600, 250, m_pDC[_BGIMAGE2], 0, 0, SRCCOPY);
	else m_pDC[_BG]->BitBlt(0, 0, 1600, 250, m_pDC[_BGIMAGE], 0, 0, SRCCOPY);

	m_pDC[_LOWERPANEL]->BitBlt(0, 0, 1600, 100, m_pDC[_LOWERPANELIMAGE], 0, 0, SRCCOPY);
	UpdateMana();
	m_pDC[_BANNER]->BitBlt(0, 0, 1600, 100, m_pDC[_BANNERIMAGE], 0, 0, SRCCOPY);

	if (dlg.bChacked == true) {
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_MAWANG), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);

	}
	

	return 0;
}


void CChildView::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_pSocket->ShutDown();
	m_pSocket->Close();
	delete m_pSocket;


	for (int i = 0; i < NoOfDC; i++)
	{
		m_pDC[i]->SelectObject(m_pOldBitmap[i]);
		delete m_pBitmap[i];
		delete m_pBmpInfo[i];
		delete m_pDC[i];
	}

	for (int i = 0; i < 6; i++) {
		delete m_pBtn[i];
	}
}


afx_msg LRESULT CChildView::OnSmReceiveddata(WPARAM wParam, LPARAM lParam)
{
//	AfxMessageBox(_T("Socket에서 메시지 왔어요 "));
	int nTemp;

	int nTeam;
	int nCount;
	int nState;
	int nPos;
	int nHp;
	int nChartype;
	unsigned char* pCurrent;

	pCurrent = m_szReceive;
	CRect rect(0, 100, 1600, 350);

	switch (m_szReceive[0]) {
	case INFORM_TEAM:
		nTemp = m_szReceive[1];
		ASSERT(nTemp == 1 || nTemp == 2);
		m_team = nTemp;  // team 이 1 이나 2가 되네 
		CreateButtons(m_team);  // 팀에 따라 버튼 위치 결정 생성
		
		m_pDC[_BANNER]->BitBlt(0, 0, 1600, 100, m_pDC[_BANNERIMAGE], 0, 0, SRCCOPY);
		if (m_team == 1) m_pDC[_BANNER]->TextOutW(50, 30, CString(_T("Player1")) );
		else m_pDC[_BANNER]->TextOutW(1500, 30, CString(_T("Player2")) );
		InvalidateRect(CRect(0, 0, 1600, 100), false);

		break;
	case GAME_DATA:

		if (bBg2) m_pDC[_BG]->BitBlt(0, 0, 1600, 250, m_pDC[_BGIMAGE2], 0, 0, SRCCOPY);
		else m_pDC[_BG]->BitBlt(0, 0, 1600, 250, m_pDC[_BGIMAGE], 0, 0, SRCCOPY);

		pCurrent++;
		nTeam = *pCurrent;
		pCurrent++;
		nCount = *pCurrent;
		pCurrent++;
		if (m_team == 1) {
			m_Mana = *pCurrent * 100;
			pCurrent++;
			m_Mana += *pCurrent;
			pCurrent++;
			DisplayUnitCount(nCount);
		}
		else {
			pCurrent += 2;
		}
		
		for (int i = 0; i < nCount; i++)
		{
			nHp = (*pCurrent) * 100;
			pCurrent++;
			nHp += *pCurrent;
			pCurrent++;
			nPos = (*pCurrent) * 100;
			pCurrent++;
			nPos += *pCurrent;
			pCurrent++;
			nChartype = *pCurrent;
			pCurrent++;
			nState = *pCurrent;
			pCurrent++;

			ASSERT(nChartype >= 0 && nChartype < 6);

			switch (nChartype) {
			case 4:
				nTemp = _DRAGON1 + nState;
				m_pDC[_BG]->TransparentBlt(nPos - m_pBmpInfo[nTemp]->bmWidth, 30, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 3:
				nTemp = _GOLEM1 + nState;
				m_pDC[_BG]->TransparentBlt(nPos - m_pBmpInfo[nTemp]->bmWidth, 100, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 2:
				nTemp = _WIZARD1 + nState;
				m_pDC[_BG]->TransparentBlt(nPos - m_pBmpInfo[nTemp]->bmWidth, 50, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 1:
				nTemp = _ARCHER1 + nState;
				m_pDC[_BG]->TransparentBlt(nPos - m_pBmpInfo[nTemp]->bmWidth, 100, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 5:
				nTemp = _SKELETON1 + nState;
				m_pDC[_BG]->TransparentBlt(nPos - m_pBmpInfo[nTemp]->bmWidth, 130, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 0:			
				nTemp = _WARRIOR1 + nState;
				m_pDC[_BG]->TransparentBlt(nPos - m_pBmpInfo[nTemp]->bmWidth, 100, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));

				
			}

		}
		nTeam = *pCurrent;
		pCurrent++;
		nCount = *pCurrent;
		pCurrent++;

		if (m_team == 2) {
			m_Mana = *pCurrent * 100;
			pCurrent++;
			m_Mana += *pCurrent;
			pCurrent++;
			DisplayUnitCount(nCount);
		}
		else {
			pCurrent += 2;
		}

		for (int i = 0; i < nCount; i++)
		{
			nHp = (*pCurrent) * 100;
			pCurrent++;
			nHp += *pCurrent;
			pCurrent++;
			nPos = (*pCurrent) * 100;
			pCurrent++;
			nPos += *pCurrent;
			pCurrent++;
			nChartype = *pCurrent;
			pCurrent++;
			nState = *pCurrent;
			pCurrent++;

			switch (nChartype) {
			case 4:
				nTemp = _DRAGON5 + nState;
				m_pDC[_BG]->TransparentBlt(nPos, 30, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 3:
				nTemp = _GOLEM5 + nState;
				m_pDC[_BG]->TransparentBlt(nPos, 100, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 2:
				nTemp = _WIZARD5 + nState;
				m_pDC[_BG]->TransparentBlt(nPos, 50, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 1:
				nTemp = _ARCHER5 + nState;
				m_pDC[_BG]->TransparentBlt(nPos, 100, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 5:
				nTemp = _SKELETON5 + nState;
				m_pDC[_BG]->TransparentBlt(nPos, 130, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));
				break;
			case 0:
				nTemp = _WARRIOR5 + nState;
				m_pDC[_BG]->TransparentBlt(nPos, 100, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight,
					m_pDC[nTemp], 0, 0, m_pBmpInfo[nTemp]->bmWidth, m_pBmpInfo[nTemp]->bmHeight, RGB(255, 255, 255));

			}
		}

		InvalidateRect(rect, false);
		UpdateMana(); 
		// 필요 마나에 따라 버튼을 활성화 시킴
		for (int i = 0; i < 6; i++) {
			if (nCost[i] <= m_Mana) m_pBtn[i]->EnableWindow(true);
			else  m_pBtn[i]->EnableWindow(false);
		}

		break;
	case GAMEEND:
		if (m_szReceive[1] == m_team) AfxMessageBox(_T("게임에 승리 했어요"));
		else AfxMessageBox(_T(" You Lose !!"));
		for (int i = 0; i < 6; i++) m_pBtn[i]->EnableWindow(false);
		m_pBtn[6]->EnableWindow(true);
		break;
		
	default:
		AfxMessageBox(_T("Socekt Data Error, 종료합니다"));
		PostQuitMessage(0);
	}

	return 0;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_LEFT:
//		if (ScreenX == 0) break;
//		ScreenX -= 25;
//		Invalidate();
//		InvalidateRect(CRect(0, 100, 800, 350), true);
		break;
	case VK_RIGHT:
//		if (ScreenX == 800) break;
//		ScreenX += 25;
//		Invalidate();
//		InvalidateRect(CRect(0, 100, 800, 350), true);
		break;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


afx_msg LRESULT CChildView::OnSmButtonclick(WPARAM wParam, LPARAM lParam)
{
	SendBtnClickMsg((int)wParam);
	for (int i = 0; i < 6; i++) {
		m_pBtn[i]->EnableWindow(false);
	}

	if (wParam == 6) m_pBtn[6]->EnableWindow(false);
 
	return 0;
}


//버튼ID는 CharType
void CChildView::SendBtnClickMsg(int btnID)
{
	m_szSend[0] = BTN_CLICK;
	m_szSend[1] = btnID;
	m_szSend[2] = m_team;
	m_pSocket->Send(m_szSend, 1024);
}



void CChildView::UpdateMana()
{
	CString str;
	str.Format(_T("Mana : %4d"), m_Mana);
	if (m_team == 1)
	{
		m_pDC[_LOWERPANEL]->BitBlt(manaRectP1.left, manaRectP1.top, manaRectP1.Width(), manaRectP1.Height(), m_pDC[_LOWERPANELIMAGE], manaRectP1.left, manaRectP1.top, SRCCOPY);
		m_pDC[_LOWERPANEL]->DrawTextW(str, manaRectP1, NULL);
		InvalidateRect(manaRectP1Wnd, false);
	}
	else {
		m_pDC[_LOWERPANEL]->BitBlt(manaRectP2.left, manaRectP2.top, manaRectP2.Width(), manaRectP2.Height(), m_pDC[_LOWERPANELIMAGE], manaRectP2.left, manaRectP1.top, SRCCOPY);
		m_pDC[_LOWERPANEL]->DrawTextW(str, manaRectP2, NULL);
		InvalidateRect(manaRectP2Wnd, false);
	}


}


void CChildView::CreateButtons(int team)
{
	for (int i = 0; i < 7; i++) {
		m_pBtn[i] = new CMyButton(this, i);
		m_pBtn[i]->Create(_T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(150+(i*90)+(team-1)*650, 370, 235+(i*90)+(team-1)*650, 430), this, i);
		m_pBtn[i]->SetWindowTextW(strBtn[i]);
		m_pBtn[i]->EnableWindow(false);
	}

	m_pBtn[6]->EnableWindow(true);
	m_pDC[_LOWERPANEL]->BitBlt(0, 0, 1600, 100, m_pDC[_LOWERPANELIMAGE], 0, 0, SRCCOPY);
	InvalidateRect(rectLowerPanal);
	
}


void CChildView::DisplayUnitCount(int nCount)
{
	CString strDisp;
	m_pDC[_BANNER]->BitBlt(0, 0, 1600, 100, m_pDC[_BANNERIMAGE], 0, 0, SRCCOPY);
	if (m_team == 1) m_pDC[_BANNER]->TextOutW(20, 30, CString(_T("Player1")));
	else m_pDC[_BANNER]->TextOutW(1500, 30, CString(_T("Player2")));

	strDisp.Format(_T("Unit Count : %3d"), nCount);
	if (m_team == 1) m_pDC[_BANNER]->TextOutW(120, 30, strDisp);
	else m_pDC[_BANNER]->TextOutW(1380, 30, strDisp);
	InvalidateRect(CRect(0, 0, 1600, 100), false);
}
