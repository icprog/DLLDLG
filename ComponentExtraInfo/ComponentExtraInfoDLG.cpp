// ComponentExtraInfoDLG.cpp : implementation file
//

#include "stdafx.h"
#include "ComponentExtraInfo.h"
#include "ComponentExtraInfoDLG.h"
#include "afxdialogex.h"
#include "DLGUIData.h"


// ComponentExtraInfoDLG dialog

IMPLEMENT_DYNAMIC(ComponentExtraInfoDLG, CDialogEx)

ComponentExtraInfoDLG::ComponentExtraInfoDLG(CWnd* pParent ,ExtraInfoDisplayData* SyncDATA)
	: CDialogEx(ComponentExtraInfoDLG::IDD, pParent)
{
	_UIData=SyncDATA;
}

ComponentExtraInfoDLG::~ComponentExtraInfoDLG()
{
}

void ComponentExtraInfoDLG::RefreshUIData()
{

}

void ComponentExtraInfoDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ComponentExtraInfoDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ComponentExtraInfoDLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// ComponentExtraInfoDLG message handlers

void ComponentExtraInfoDLG::AdjustLayout(CRect & inputRect)
{
	SetWindowPos(&CWnd::wndTop,inputRect.left,inputRect.top,inputRect.Width(),inputRect.Height(),SWP_SHOWWINDOW);

	RedrawWindow();
}

void ComponentExtraInfoDLG::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}
