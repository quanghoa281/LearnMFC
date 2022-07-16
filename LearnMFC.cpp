// LearnMFC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "LearnMFC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



BEGIN_MESSAGE_MAP(CLearnMFC, CWinApp)
	//{{AFX_MSG_MAP(CLearnMFC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CLearnMFC::CLearnMFC()
{
	// support Restart Manager
	//m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CLearnMFC::~CLearnMFC()
{
}

CLearnMFC theApp;

BOOL CLearnMFC::InitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	UINT stop;
	CBrush cbrush;
	HICON hicon = LoadIcon(IDI_ICON1);
	
	cbrush.CreateSolidBrush(RGB( 0, 255, 255));
	CDemo* main = new CDemo();
	CRect rect(0, 0, 200, 200);
	CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, NULL, cbrush, NULL);
	main->CreateEx(WS_EX_TOPMOST, className, _T("quanghoa281"), WS_SYSMENU | WS_CAPTION | WS_VISIBLE |/* WS_CLIPSIBLINGS | WS_CLIPCHILDREN*/ WS_THICKFRAME, rect, NULL, 0);
	m_pMainWnd = main;
	main->init(hicon);
	MoveWindow(main->GetSafeHwnd(), 300, 300, 900, 900, true);
	main->ShowWindow(SW_SHOWNORMAL);
	/*do {
		stop = AfxMessageBox(m_lpCmdLine,
			MB_YESNO | MB_ICONQUESTION, 0);
		Sleep(10000);
	} while (stop == IDNO);*/

	return CWinApp::InitInstance();
}
