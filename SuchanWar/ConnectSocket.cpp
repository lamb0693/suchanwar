// ConnectSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SuchanWar.h"
#include "ConnectSocket.h"
#include "ChildView.h"


// CConnectSocket

CConnectSocket::CConnectSocket(CView* pView)
{
	m_pView = pView;
}

CConnectSocket::~CConnectSocket()
{
}


// CConnectSocket 멤버 함수


void CConnectSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("Server와의 연결이 끊겼어요"));
	::PostQuitMessage(0);
}


void CConnectSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//	char szBuffer[1024];
//	::ZeroMemory(szBuffer, sizeof(szBuffer));

	CChildView* pView = (CChildView*)m_pView;

	if (Receive(pView->m_szReceive, 1024) > 0) {
		pView->SendMessage(SM_RECEIVEDDATA, NULL, NULL);
	}

	CSocket::OnReceive(nErrorCode);
}
