/**
 *							Project Keylogger
 */


#ifndef						_KEYBOARDHOOK_H
#define						_KEYBOARDHOOK_H

#include					"AHook.h"


class __declspec(dllexport) KeyboardHook: public AHook {
public: 
    
KeyboardHook(const HookObserver&);
	const bool				setHook();
    static LRESULT CALLBACK keyboardhook(const int, const LPARAM, const WPARAM);
};

#endif //_KEYBOARDHOOK_H