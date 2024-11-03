
// IND_18753.h : main header file for the IND_18753 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CIND18753App:
// See IND_18753.cpp for the implementation of this class
//

class CIND18753App : public CWinApp
{
public:
	CIND18753App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIND18753App theApp;
