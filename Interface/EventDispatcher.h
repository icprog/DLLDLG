#ifndef __EVENT_DISPATCHER_GENERIC__
#define __EVENT_DISPATCHER_GENERIC__

#include <map>

class IDLLUIEvent;

template<class EventEnum>
class EventDispatcher
{
public:
	EventDispatcher()
	{

	}
	
	~EventDispatcher()
	{
		std::map<EventEnum,IDLLUIEvent*>::iterator pos=_EventMap.begin();
		std::map<EventEnum,IDLLUIEvent*>::iterator endpos=_EventMap.end();
		for(;pos!=endpos;pos++)
		{
			if(pos->second)
				delete pos->second;
		}

		_EventMap.clear();
	}
	
	void AddEvent(EventEnum input, IDLLUIEvent* eventhandler) /// Currently only one event at a time
	{
		IDLLUIEvent* ret=GetEvent(input);
		
		if(ret) // clear exist event
			delete ret;

		_EventMap[input]=eventhandler;
	}

	IDLLUIEvent* GetEvent(EventEnum input)
	{
		std::map<EventEnum,IDLLUIEvent*>::iterator pos=_EventMap.find(input);
		if(pos!=_EventMap.end())
			return pos->second;
		else
			return NULL;
	}

private:
	std::map<EventEnum,IDLLUIEvent*>  _EventMap;
};

#endif

