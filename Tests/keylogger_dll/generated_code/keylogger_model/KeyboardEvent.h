/**
 * Project Keylogger
 */


#ifndef _KEYBOARDEVENT_H
#define _KEYBOARDEVENT_H

#include "AEvent.h"


class __declspec(dllexport) KeyboardEvent: public AEvent {
public: 
    
     KeyboardEvent(const int virtualKeyCode, const int repeatCount, const char scanCode, const bool isExtend, const bool isAlt, const bool prevKeyState, const bool transState, const std::chrono::milliseconds & time, const t_Context context);
};

#endif //_KEYBOARDEVENT_H