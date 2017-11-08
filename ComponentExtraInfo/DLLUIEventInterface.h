#ifndef __DLL_UI_EVENT_INTERFACE__
#define __DLL_UI_EVENT_INTERFACE__

class IDLLUIEvent
{
public:
	virtual ~IDLLUIEvent(){}
	virtual void OnEvent()=0;
};

#endif