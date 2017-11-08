// ComponentExtraInfo.h : main header file for the ComponentExtraInfo DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CComponentExtraInfoApp
// See ComponentExtraInfo.cpp for the implementation of this class
//

class CComponentExtraInfoApp : public CWinApp
{
public:
	CComponentExtraInfoApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
