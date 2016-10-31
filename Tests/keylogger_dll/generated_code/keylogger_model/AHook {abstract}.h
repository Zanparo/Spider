/**
 * Project Keylogger
 */


#ifndef _AHOOK {ABSTRACT}_H
#define _AHOOK {ABSTRACT}_H

class AHook {abstract} {
public: 
    
    /**
     * @param HookObserver&
     */
    void AHook(void HookObserver&);
    
    /**
     * Encapsulate methods to set a hook process
     */
    virtual bool setHook() = 0;
    
    /**
     * Return the HINSTANCE
     */
    HINSTANCE & getHinstance();
    
    /**
     * Notify the HookObserver _observer that a callback have been called.
     * @param int
     * @param LPARAM
     * @param WPARAM
     */
    void notify(void int, void LPARAM, void WPARAM);
    
    bool unsetHook();
private: 
    HINSTANCE _hinstance;
    HooKObserver _observer;
};

#endif //_AHOOK {ABSTRACT}_H