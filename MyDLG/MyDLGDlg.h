
// MyDLGDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "..\ComponentExtraInfo\DLGUIData.h"
#include "..\ComponentExtraInfo\TIDLLUIPlugin.h"
#include "TemplateDLLLoader.h"

typedef IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData>  MyDLLType;

typedef IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData> *(*PluginCreateor)();
typedef DLLLoader<IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData>*, PluginCreateor> MyDLLLoader;


/*class IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData>;*/
// CMyDLGDlg dialog
class CMyDLGDlg : public CDialogEx
{
// Construction
public:
	CMyDLGDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MYDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic m_GroupREct;
	MyDLLType *_ptr;
	MyDLLLoader *_DLLCREATOR;
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton2();
};
