/**
 * Project Keylogger
 */


#ifndef _HOOKOBSERVER_H
#define _HOOKOBSERVER_H

class HookObserver {
public: 
    
    /**
     * @param EventManager&
     */
    void HookObserver(void EventManager&);
    
    /**
     * update must notify the EventManager that an event should be created. To do this, call 
     * @param LPARAM
     * @param WPARAM
     */
    void update(void LPARAM, void WPARAM);
private: 
    EventManager& _eventManager;
};

#endif //_HOOKOBSERVER_H