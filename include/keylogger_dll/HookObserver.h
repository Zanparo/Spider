/**
 *									Project Keylogger
 */


#ifndef								_HOOKOBSERVER_H
#define								_HOOKOBSERVER_H

#include							"EventManager.h"

class								HookObserver {

public:     
    HookObserver(const EventManager&);
    void							update(const WPARAM, const LPARAM) const;

private: 
    const EventManager&				_eventManager;
};

#endif //_HOOKOBSERVER_H