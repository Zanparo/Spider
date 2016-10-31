/**
 * Project Keylogger
 */


#ifndef _EVENTFACTORY_H
#define _EVENTFACTORY_H

class EventFactory {
public: 
    
    void EventFactory();
    
    /**
     * Function to create an Event with LPARAM and WPARAM
     * @param LPARAM
     * @param WPARAM
     */
    static AEvent* create(void LPARAM, void WPARAM);
};

#endif //_EVENTFACTORY_H