#pragma once

#include <map>
#include "Resource.h"
#include "afxwin.h"
#include "ShareData\DLGUIData.h"
#include "..\Interface\EventDispatcher.h"
#include "ShareData\ComponentExtraEvent.h"

// ComponentExtraInfoDLG dialog
class ExtraInfoDisplayData;
class IDLLUIEvent;

class ComponentExtraInfoDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ComponentExtraInfoDLG)

public:
	ComponentExtraInfoDLG(CWnd* pParent ,ExtraInfoDisplayData* SyncDATA,EventDispatcher<COMPEXTRA_EVENT> * EventCallBak);   // standard constructor
	virtual ~ComponentExtraInfoDLG();

// Dialog Data
	enum { IDD = IDD_EXTRAINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	ExtraInfoDisplayData*  _UIData;
	EventDispatcher<COMPEXTRA_EVENT> * _EventCallBak;

	std::map<MFCTRL_ENUM,CWnd*> _MFCCtrlList;

	IDLLUIEvent* GetCalBakEvent(COMPEXTRA_EVENT  input);
public:
	void RefreshUIData();
	void AdjustLayout(CRect & inputRect);
	afx_msg void OnBnClickedButton1();

	CListCtrl m_ListBox;
};
