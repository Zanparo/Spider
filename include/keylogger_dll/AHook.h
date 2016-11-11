/**
 *							Project Keylogger
 */


#ifndef						_AHOOK_H
#define						_AHOOK_H

#include					"IHook.h"
#include					"IHookObserver.h"

class						AHook : public IHook {
public: 
    
   AHook(const IHookObserver&);
   ~AHook();
    
    virtual const bool		setHook() = 0;
    void					notify(int, WPARAM, LPARAM);
    bool					unsetHook();
	const HHOOK				getHook() const;

protected: 

	HHOOK					_hHook;
	const IHookObserver&	_observer;
};

#endif //_AHOOK {ABSTRACT}_H