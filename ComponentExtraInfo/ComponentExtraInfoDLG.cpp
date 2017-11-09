// ComponentExtraInfoDLG.cpp : implementation file
//

#include "stdafx.h"
#include "ComponentExtraInfo.h"
#include "ComponentExtraInfoDLG.h"
#include "afxdialogex.h"
#include "ShareData\DLGUIData.h"
#include "..\Interface\DLLUIEventInterface.h"


// ComponentExtraInfoDLG dialog

IMPLEMENT_DYNAMIC(ComponentExtraInfoDLG, CDialogEx)

ComponentExtraInfoDLG::ComponentExtraInfoDLG(CWnd* pParent ,ExtraInfoDisplayData* SyncDATA, EventDispatcher<COMPEXTRA_EVENT> * EventCallBak)
	: CDialogEx(ComponentExtraInfoDLG::IDD, pParent)
{
	_UIData=SyncDATA;
	_EventCallBak=EventCallBak;
}

ComponentExtraInfoDLG::~ComponentExtraInfoDLG()
{
}

void ComponentExtraInfoDLG::RefreshUIData()
{
	if(!_UIData)
		return;

	std::vector<DispData*> curData=_UIData->GetDisplayData();
	const size_t num_Data=curData.size();
	
	for(size_t i=0;i<num_Data;i++)
	{
		CString DISPITem;
		DISPITem.Format(_T("%s___%s"),curData[i]->_ComponentTypeName,curData[i]->_ComponentDataName);
		//m_ListBox.InsertItem(AddString(DISPITem));
	}
}

void ComponentExtraInfoDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ListBox);
}


BEGIN_MESSAGE_MAP(ComponentExtraInfoDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ComponentExtraInfoDLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// ComponentExtraInfoDLG message handlers

void ComponentExtraInfoDLG::AdjustLayout(CRect & inputRect)
{
	if(!GetSafeHwnd())
		return;

	SetWindowPos(&CWnd::wndTop,inputRect.left,inputRect.top,inputRect.Width(),inputRect.Height(),SWP_SHOWWINDOW);

	RedrawWindow();
}

void ComponentExtraInfoDLG::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	IDLLUIEvent*  pCurCalbak=GetCalBakEvent(COMPEXTRA_EVENT_CLICK_REFRESH_BTN);
	if(pCurCalbak)
		pCurCalbak->OnEvent();
}

IDLLUIEvent*  ComponentExtraInfoDLG::GetCalBakEvent(COMPEXTRA_EVENT  input)
{
	IDLLUIEvent* ret=NULL;

	if(_EventCallBak)
		ret=_EventCallBak->GetEvent(input);

	return ret;
}