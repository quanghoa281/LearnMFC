#pragma once

#include "resource.h"
#include "CDemo.h"

class CLearnMFC : public CWinApp {
protected:
	CDemo _cDemo;
public:
	CLearnMFC();
	virtual ~CLearnMFC();
	//{{AFX_VIRTUAL(CLearnMFC)
	//}}AFX_VIRTUAL
	//{{AFX_MSG(CLearnMFC)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	virtual BOOL InitInstance();
};
extern CLearnMFC theApp;