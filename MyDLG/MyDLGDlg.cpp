
// MyDLGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyDLG.h"
#include "MyDLGDlg.h"
#include "afxdialogex.h"
#include "TemplateDLLLoader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyDLGDlg dialog




CMyDLGDlg::CMyDLGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDLGDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	_ptr=NULL;
}

void CMyDLGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYGROUP_STATIC, m_GroupREct);
}

BEGIN_MESSAGE_MAP(CMyDLGDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDLGDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CMyDLGDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMyDLGDlg message handlers

BOOL CMyDLGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDLGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDLGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDLGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyDLGDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	_DLLCREATOR=new DLLLoader<IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData>*, PluginCreateor>(CString(_T("ComponentExtraInfo.dll")));
	_ptr=_DLLCREATOR->GetDLLCLass();
	if(_ptr)
	{
		CRect rect;
		ExtraInfoDisplayData *UIDAtaPTR=_ptr->GetUIDataObj();
		m_GroupREct.GetClientRect(&rect);
		UIDAtaPTR->DisplayRect=rect;

		_ptr->CreateUI(&m_GroupREct);
		//delete ptr;
	}


}


void CMyDLGDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	if(_ptr)
	{
		delete _ptr;
	}
	if(_DLLCREATOR)
		delete _DLLCREATOR;
	CDialogEx::OnClose();
}


void CMyDLGDlg::OnBnClickedButton2()
{
	if(_ptr)
	{
		ExtraInfoDisplayData *UIDAtaPTR=_ptr->GetUIDataObj();
		UIDAtaPTR->ListVec.push_back(new DispData());
		_ptr->RefreshDLG();
	}
	// TODO: Add your control notification handler code here
}
