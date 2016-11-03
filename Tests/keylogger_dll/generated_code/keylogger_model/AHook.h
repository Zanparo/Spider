/**
 *							Project Keylogger
 */


#ifndef						_AHOOK_H
#define						_AHOOK_H

#include					<Windows.h>

#include					"HookObserver.h"

class __declspec(dllexport)	AHook {
public: 
    
   AHook(const HookObserver&);
    
    virtual const bool		setHook() = 0;
    void					notify(int, LPARAM, WPARAM);
    bool					unsetHook();

protected: 

    const HookObserver&			_observer;
};

#endif //_AHOOK {ABSTRACT}_H