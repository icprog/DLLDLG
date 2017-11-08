#pragma once

#include <map>
#include "DLGUIData.h"
#include "Resource.h"

// ComponentExtraInfoDLG dialog

class ComponentExtraInfoDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ComponentExtraInfoDLG)

public:
	ComponentExtraInfoDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~ComponentExtraInfoDLG();

// Dialog Data
	enum { IDD = IDD_EXTRAINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	std::map<MFCTRL_ENUM,CWnd*> _MFCCtrlList;
public:
	void AdjustLayout(CRect & inputRect);
	afx_msg void OnBnClickedButton1();

};
