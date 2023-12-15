
// ChildView.h : CChildView 클래스의 인터페이스
//

#pragma once
#pragma comment(lib, "winmm")
#include "ConnectSocket.h"
#include "MyButton.h"
#include <mmsystem.h>


#define NoOfDC 55
typedef enum __ImageName
{
	_BANNER, _BG, _LOWERPANEL, _BANNERIMAGE, _BGIMAGE, _LOWERPANELIMAGE,
	_WARRIOR1, _WARRIOR2, _WARRIOR3, _WARRIOR4, _WARRIOR5, _WARRIOR6, _WARRIOR7, _WARRIOR8,
	_ARCHER1, _ARCHER2, _ARCHER3, _ARCHER4, _ARCHER5, _ARCHER6, _ARCHER7, _ARCHER8,
	_WIZARD1, _WIZARD2, _WIZARD3, _WIZARD4, _WIZARD5, _WIZARD6, _WIZARD7, _WIZARD8,
	_GOLEM1, _GOLEM2, _GOLEM3, _GOLEM4, _GOLEM5, _GOLEM6, _GOLEM7, _GOLEM8, 
	_DRAGON1, _DRAGON2, _DRAGON3, _DRAGON4, _DRAGON5, _DRAGON6, _DRAGON7, _DRAGON8,
	_SKELETON1, _SKELETON2, _SKELETON3, _SKELETON4, _SKELETON5, _SKELETON6, _SKELETON7, _SKELETON8,
	_BGIMAGE2
} _IMAGENAME;

// CChildView 창

class CChildView : public CWnd
{
	// 생성입니다.
public:
	CChildView();

	// 특성입니다.
public:
	CConnectSocket* m_pSocket;
	int m_team;
	int m_Mana;
	//	CString strReceived;
	unsigned char m_szReceive[1024];
	unsigned char m_szSend[1024];


	CBitmap* m_pBitmap[NoOfDC];
	CDC* m_pDC[NoOfDC];
	BITMAP* m_pBmpInfo[NoOfDC];
	CBitmap* m_pOldBitmap[NoOfDC];

	CRect rectBG;
	CRect manaRectP1, manaRectP1Wnd;
	CRect manaRectP2, manaRectP2Wnd;
	CRect playerRect;
	CRect rectLowerPanal;

	int ScreenX;//현제 보이는 배경의 좌표

	CMyButton* m_pBtn[7];

	bool bBg2;//배경 그림이 2인가

	CString strBtn[7] = { _T("전 사(10)"), _T("궁 수(20)"), _T("마법사(30)"), _T("골렘(50)"), _T("드래곤(80)"), _T("해골군대(30)") , _T("준비완료")};

	int nCost[6] = {10, 20, 30, 50, 80, 30 };

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
protected:
	afx_msg LRESULT OnSmReceiveddata(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
protected:
	afx_msg LRESULT OnSmButtonclick(WPARAM wParam, LPARAM lParam);
public:
	void SendBtnClickMsg(int btnID);
	void UpdateMana();
	void CreateButtons(int team);
	void DisplayUnitCount(int nCount);
};

