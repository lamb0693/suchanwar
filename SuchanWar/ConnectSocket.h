#pragma once
#include "stdafx.h"

// CConnectSocket ��� ����Դϴ�.

class CConnectSocket : public CSocket
{
public:
	CConnectSocket(CView* pView);
	virtual ~CConnectSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);

	CView* m_pView;
};


