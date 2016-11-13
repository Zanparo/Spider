/**
 *									Project Keylogger
 */


#ifndef								_HOOKOBSERVER_H
#define								_HOOKOBSERVER_H

#include							"AHookObserver.h"
#include							"EventManager.h"

class								KeyboardHookObserver : public AHookObserver {

public:     
    KeyboardHookObserver(const EventManager&);
	~KeyboardHookObserver();
};

#endif //_HOOKOBSERVER_H