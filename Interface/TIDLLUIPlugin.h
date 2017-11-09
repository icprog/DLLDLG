#ifndef _IDOLLUOTPLUIN__
#define _IDOLLUOTPLUIN__

#include "DLLUIEventInterface.h"
#include <afxwin.h>
#include "DLLPluginInterface.h"
#include "EventDispatcher.h"

template<class EventEnum,class UIDataObjPTR>
class UIDLL_Plugin : public IDLLPluginInterface
{
public:
	UIDLL_Plugin()
	{
		_OBJ=new UIDataObjPTR();
	}
	virtual ~UIDLL_Plugin() 
	{
		if(_OBJ)
			delete _OBJ;
	}
	
	virtual void RefreshDLG()=0;
	virtual void AdjustLaytout()=0;
	virtual void CreateUI(CWnd* parent)=0;
	
	void AddEventCtrl(EventEnum input,IDLLUIEvent * eventHandler)
	{
		_eventMap.AddEvent(input,eventHandler);
	}

	UIDataObjPTR* GetUIDataObj()
	{
		return _OBJ;
	}

	EventDispatcher<EventEnum>* GetEventHandler()
	{
		return &_eventMap;
	}
protected:
	UIDataObjPTR* _OBJ;
	EventDispatcher<EventEnum>   _eventMap;
private:
	
};


#endif