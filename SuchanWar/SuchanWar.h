
// SuchanWar.h : SuchanWar ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSuchanWarApp:
// �� Ŭ������ ������ ���ؼ��� SuchanWar.cpp�� �����Ͻʽÿ�.
//

class CSuchanWarApp : public CWinApp
{
public:
	CSuchanWarApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSuchanWarApp theApp;
