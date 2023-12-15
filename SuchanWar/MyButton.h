#pragma once


// CMyButton

class CMyButton : public CButton
{
	DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton(CWnd* pWnd, int nID);
	virtual ~CMyButton();
	CWnd* m_pWnd;
	int m_nButtonID;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


