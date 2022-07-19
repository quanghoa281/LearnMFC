// CDemo.cpp : implementation file
//

#include <iostream>
#include "pch.h"
#include "resource.h"
#include "LearnMFC.h"
#include "CDemo.h"


// CDemo

IMPLEMENT_DYNAMIC(CDemo, CWnd)

CDemo::CDemo()
{
	ntime = 100;
	_cps.x = 0;
	_cps.y = 0;
	_direc = 1;
	_bcx = 100;
	_bcy = 100;

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
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


void CDemo::init(HICON hicon)
{
	SetIcon(hicon, TRUE);
}

int CDemo::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// edit shape of form
	/*
	CRgn newShape;
	newShape.CreateRoundRectRgn(100, 100, 600, 600, 30, 30);
	HGDIOBJ hRgn = newShape.Detach();
	CBrush brA, brB, brC;
	VERIFY(brA.CreateSolidBrush(RGB(255, 0, 0)));
	FrameRgn(dc, newShape, brA, 2, 2);*/
	_bitmap.LoadBitmap(IDB_BITMAP_BK);
	_buom.LoadBitmap(IDB_BITMAP_B);

	CRect crect;
	this->GetClientRect(crect);
	_pos = new CPosition(0, 0, crect.Width(), crect.Height(), _bcx, _bcy, 20);
	if (_pos->getDirect() == 1) {
		_idx = 0;
	}
	else {
		_idx = 3;
	}
	SetTimer(ntime, ntime, NULL);

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
		CRect crect;
		this->GetClientRect(crect);

		Invalidate(true);
	}
	CWnd::OnTimer(nIDEvent);
}


void CDemo::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	/*if (AfxMessageBox(L"are you want close app?", MB_YESNO) == IDNO)
	{
		return;
	}*/
	CWnd::OnClose();
}


void CDemo::OnDestroy()
{
	CWnd::OnDestroy();
	KillTimer(ntime);
	_bitmap.DeleteObject();
	// TODO: Add your message handler code here
}


void CDemo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages
	CRect crect2;
	CBitmap* bmObj;
	BITMAP bmbuom;
	CDC memDC;

	this->GetClientRect(crect2);
	_buom.GetBitmap(&bmbuom);
	memDC.CreateCompatibleDC(&dc);
	bmObj = memDC.SelectObject(&_buom);
	int len = bmbuom.bmWidth / 6;
	CPoint cpot = _pos->getPos();
	dc.StretchBlt(cpot.x, cpot.y, _bcx, _bcy, &memDC, _idx * len, 0, len, bmbuom.bmHeight, SRCCOPY);
	_pos->calx(), _pos->caly();
	if (_pos->getDirect() == 1) {
		if (_idx > 2) _idx = 2;
		if (_idx == 2) {
			_sttcbr = false;
		}
		else if (_idx == 0) {
			_sttcbr = true;
		}
		if (_sttcbr)_idx++;
		else _idx--;
	}
	else {
		if (_idx < 3) _idx = 3;
		if (_idx == 5) {
			_sttcbr = false;
		}
		else if (_idx == 3) {
			_sttcbr = true;
		}
		if (_sttcbr)_idx++;
		else _idx--;
	}


	//CPen cpen(PS_SOLID, 3, RGB(255, 0, 0));
	//dc.SelectObject(cpen);
	//dc.MoveTo(px, 200);
	//dc.LineTo(px + 50, 200);
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.SetBkMode(TRANSPARENT);
	//dc.TextOutW(px, py, L"quanghoa281");

	//CRect crect(0 + px, 300, 100 + px, 400);
	//dc.Draw3dRect(crect, RGB(255, 0, 0), RGB(0, 0, 255));

	//dc.SelectObject(cpen);
	//CRect crect1(0, 500, 100, 600);
	//dc.DrawEdge(crect1, BDR_RAISEDOUTER | BDR_SUNKENOUTER, BF_RECT);


	//memDC.SelectObject(bmObj);
	memDC.SelectObject(bmObj);
	memDC.DeleteDC();
}


HBRUSH CDemo::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
