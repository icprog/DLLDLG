#ifndef _IDOLLUOTPLUIN__
#define _IDOLLUOTPLUIN__

#include "DLLUIEventInterface.h"
#include <afxwin.h>

template<class EventEnum,class UIDataObjPTR>
class IDLLUI_Plugin
{
public:
	IDLLUI_Plugin()
	{
		_OBJ=new UIDataObjPTR();
	}
	virtual ~IDLLUI_Plugin() 
	{
		if(_OBJ)
			delete _OBJ;
	}
	virtual void AddEventCtrl(EventEnum input,IDLLUIEvent * eventHandler)=0;
	virtual void RefreshDLG()=0;
	virtual void AdjustLaytout()=0;
	virtual void CreateUI(CWnd* parent)=0;

	UIDataObjPTR* GetUIDataObj()
	{
		return _OBJ;
	}
protected:
	UIDataObjPTR* _OBJ;
private:
	
};


#endif