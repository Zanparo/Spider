/**
 * Project Keylogger
 */


#ifndef _HOOKHANDLER_H
#define _HOOKHANDLER_H

class HookHandler {
public: 
    
    /**
     * @param EventManager&
     */
    void HookHandler(void EventManager&);
    
    /**
     * Add the AHook parameter to the list of hooks the handler contains.
     * 
     * @param AHook
     */
    bool AddHook(void AHook);
    
    /**
     * Remove the AHook& paramater from the hook list contained by the HookHandler
     * 
     * @param const AHook&
     */
    bool RemoveHook(void const AHook&);
private: 
    List<AHook*> _hooks;
    EventManager& _eventManager;
    HookHandler _instance;
};

#endif //_HOOKHANDLER_H