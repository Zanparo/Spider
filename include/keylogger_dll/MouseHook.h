/**
 *							Project Keylogger
 */


#ifndef						_MOUSEHOOK_H
#define						_MOUSEHOOK_H

#include					<Windows.h>
#include					<iostream>

#include					"AHook.h"

class  MouseHook: public AHook {

public: 
    
MouseHook(const IHookObserver&);
const bool					setHook();    
static LRESULT CALLBACK		mousehook(int, WPARAM, LPARAM);
};

#endif //_MOUSEHOOK_H