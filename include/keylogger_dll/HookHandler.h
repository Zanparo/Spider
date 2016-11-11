/**
 *									Project Keylogger
 */


#ifndef								_HOOKHANDLER_H
#define								_HOOKHANDLER_H 
	
#include							<vector>
	
#include							"EventManager.h"
#include							"KeyboardHook.h"
#include							"MouseHook.h"
#include							"KeyboardHookObserver.h"
#include							"MouseHookObserver.h"

class								HookHandler {
public: 
    HookHandler(const EventManager&);
    const bool						addHook(IHook*);
    const bool						removeHook(IHook*);
	const bool						init();
	const bool						stop();

private: 
	std::vector<IHook*>				_hooks;
    const EventManager&				_eventManager;
};

#endif								//_HOOKHANDLER_H