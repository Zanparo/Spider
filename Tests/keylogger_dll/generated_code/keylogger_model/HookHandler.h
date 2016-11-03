/**
 *									Project Keylogger
 */


#ifndef								_HOOKHANDLER_H
#define								_HOOKHANDLER_H __declspec(dllimport)
	
#include							<vector>
	
#include							"EventManager.h"
#include							"AHook.h"

class __declspec(dllexport)			HookHandler {
public: 
    HookHandler(const EventManager&);
    const bool						AddHook(AHook*);
    const bool						RemoveHook(AHook*);

private: 
	std::vector<AHook*>				_hooks;
    const EventManager&				_eventManager;
};

#endif //_HOOKHANDLER_H