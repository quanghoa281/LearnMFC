// CDemo.cpp : implementation file
//

#include "pch.h"
#include <iostream>
#include "LearnMFC.h"
#include "CDemo.h"


// CDemo

IMPLEMENT_DYNAMIC(CDemo, CWnd)

CDemo::CDemo()
{
	ntime = 20;
	px = 0;
	py = 50;
}

CDemo::~CDemo()
{
}

BEGIN_MESSAGE_MAP(CDemo, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CDemo::init(HICON hicon)
{
	SetIcon(hicon, TRUE);
}

int CDemo::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetTimer(ntime, ntime,NULL);

	return 0;
}

void CDemo::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (cx <= 0 || cy <= 0 || nType == SIZE_MINIMIZED)
		return;

	switch (nType)
	{
	case SIZE_MAXIMIZED:
		MoveWindow(0, 0, cx, cy);
		GetWindowRect(_rect);
		_oldWindow = _rect;
		break;
	case SIZE_RESTORED:
		//if (_isMaximized)
		//{
		//	MoveWindow(0, 0, cx, cy);	//execute 9 times (reason unknown)
		//	GetWindowRect(_rect);
		//	_oldWindow = _rect;
		//}
		break;
	case SIZE_MINIMIZED:
		MoveWindow(0, 0, cx, cy);
		GetWindowRect(_rect);
		_oldWindow = _rect;
	default:
		break;
	}
}


void CDemo::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == ntime) {
		char ch;
		CString ss;
		CRect crect;
		this->GetClientRect(crect);
		int lenmax = crect.Width() / 3.5;
		GetWindowText(ss);
		int len = ss.GetLength();
		CString ssplus = _T("");
		if (lenmax > len) {
			std::string a; a.assign(lenmax - len, ' ');
			ssplus = CString(a.c_str());
		}
		ss += ssplus;
		len = ss.GetLength();
		ch = ss.GetAt(len-1);
		int i = 0;
		for (i = len-1; i > 0; i--)
		{
			ss.SetAt(i,ss.GetAt(i-1));
		}
		ss.SetAt(i, ch);
		SetWindowText(ss);
		//
		if (px <= crect.Width() - 10) {
			px += 10;
		}
		else {
			px = 0;
		}
		Invalidate(true);
	}
	CWnd::OnTimer(nIDEvent);
}


void CDemo::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	if (AfxMessageBox(L"are you want close app?", MB_YESNO) == IDNO)
	{
		return;
	}
	CWnd::OnClose();
}


void CDemo::OnDestroy()
{
	CWnd::OnDestroy();
	KillTimer(ntime);
	// TODO: Add your message handler code here
}


void CDemo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages
	CPen cpen(PS_SOLID, 3, RGB(255,0,0));
	dc.SelectObject(cpen);
	dc.MoveTo(px, 200);
	dc.LineTo(px+50, 200);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOutW(px, py, L"quanghoa281");

	CRect crect(0+px,300, 100 + px,400);
	dc.Draw3dRect(crect, RGB(255, 0, 0), RGB(0, 0, 255));

	dc.SelectObject(cpen);
	CRect crect1(0,500, 100,600);
	dc.DrawEdge(crect1, BDR_RAISEDOUTER|BDR_SUNKENOUTER, BF_RECT);

}
