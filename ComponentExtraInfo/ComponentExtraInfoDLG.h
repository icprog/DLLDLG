#pragma once

#include <map>
#include "Resource.h"
#include "afxwin.h"
#include "ShareData\DLGUIData.h"

// ComponentExtraInfoDLG dialog
class ExtraInfoDisplayData;
class ComponentExtraInfoDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ComponentExtraInfoDLG)

public:
	ComponentExtraInfoDLG(CWnd* pParent ,ExtraInfoDisplayData* SyncDATA);   // standard constructor
	virtual ~ComponentExtraInfoDLG();

// Dialog Data
	enum { IDD = IDD_EXTRAINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	ExtraInfoDisplayData*  _UIData;
	std::map<MFCTRL_ENUM,CWnd*> _MFCCtrlList;
public:
	void RefreshUIData();
	void AdjustLayout(CRect & inputRect);
	afx_msg void OnBnClickedButton1();

	CListCtrl m_ListBox;
};
