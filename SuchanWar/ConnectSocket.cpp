// ConnectSocket.cpp : ���� �����Դϴ�.
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


// CConnectSocket ��� �Լ�


void CConnectSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("Server���� ������ ������"));
	::PostQuitMessage(0);
}


void CConnectSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//	char szBuffer[1024];
//	::ZeroMemory(szBuffer, sizeof(szBuffer));

	CChildView* pView = (CChildView*)m_pView;

	if (Receive(pView->m_szReceive, 1024) > 0) {
		pView->SendMessage(SM_RECEIVEDDATA, NULL, NULL);
	}

	CSocket::OnReceive(nErrorCode);
}
