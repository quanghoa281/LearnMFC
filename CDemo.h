#pragma once


// CDemo

class CDemo : public CWnd
{
	DECLARE_DYNAMIC(CDemo)

private:
	CRect _rect;
	CRect _oldWindow;
	int ntime;
	int px, py;
public:
	CDemo();
	virtual ~CDemo();
	void init(HICON hicon);

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
};


