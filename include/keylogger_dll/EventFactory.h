/**
 *						Project Keylogger
 */


#ifndef					_EVENTFACTORY_H
#define					_EVENTFACTORY_H

#include				<Windows.h>

#include				"KeyboardEvent.h"
#include				"MouseEvent.h"
#include				"Context.h"
#include				<chrono>
#include				<ctime>
#include				<iostream>

class  EventFactory {
public: 
    
    EventFactory();
    
    static const AEvent* createKeyboardEvent(WPARAM, LPARAM, t_Context);
	static const AEvent* createMouseEvent(WPARAM, LPARAM, t_Context);
};

#endif //_EVENTFACTORY_H