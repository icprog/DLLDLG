#ifndef __DLL_UI_EXTRA_COMP_INFO_CTRL__
#define __DLL_UI_EXTRA_COMP_INFO_CTRL__


#include "TIDLLUIPlugin.h"
#include "DLGUIData.h"
#include "DLLUIEventInterface.h"
#include "ComponentExtraInfoDLG.h"

class ExtraCompInfoCtrl : public IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData>
{
public:
	ExtraCompInfoCtrl()
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		_DLG=new ComponentExtraInfoDLG(NULL,this->GetUIDataObj());
		_Parent=NULL;
	}

	virtual ~ExtraCompInfoCtrl() 
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		if(_DLG)
			delete _DLG;
	}
	virtual void AddEventCtrl(MFCTRL_ENUM input,IDLLUIEvent * eventHandler)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
	}

	virtual void RefreshDLG()
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		AdjustLaytout();
		if(_DLG)
		{
			_DLG->RefreshUIData();
		}
		
	}

	virtual void AdjustLaytout()
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());

		if(_DLG)
		{
			ExtraInfoDisplayData* UIOBJ=GetUIDataObj();
			CRect curRect=UIOBJ->DisplayRect;
			_DLG->AdjustLayout(curRect);
		}
	}
	virtual void CreateUI(CWnd* parent)
	{
		_Parent=parent;
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		_DLG->Create(IDD_EXTRAINFO_DIALOG);
		_DLG->SetParent(_Parent);
		RefreshDLG();
		_DLG->ShowWindow(SW_SHOW);

	}
private:
	ComponentExtraInfoDLG *_DLG;
	CWnd*  _Parent;
};

#endif