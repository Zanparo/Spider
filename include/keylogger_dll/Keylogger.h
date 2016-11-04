/**
 * Project Keylogger
 */


#ifndef _KEYLOGGER_H
#define _KEYLOGGER_H

#include "AEvent.h"
#include "EventManager.h"
#include "HookHandler.h"

class Keylogger {
public:
    Keylogger();
	~Keylogger();
    bool				init();   
    void				run();
    bool				stop();
    bool				kill();
    bool pushToQueue(AEvent*);

private: 
    EventManager _eventManager;
    HookHandler _hookHandler;
    std::vector<AEvent*> _events;
};

#endif //_KEYLOGGER_H