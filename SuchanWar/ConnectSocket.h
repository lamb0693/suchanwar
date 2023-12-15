#pragma once
#include "stdafx.h"

// CConnectSocket 명령 대상입니다.

class CConnectSocket : public CSocket
{
public:
	CConnectSocket(CView* pView);
	virtual ~CConnectSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);

	CView* m_pView;
};


