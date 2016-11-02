/**
 * Project Keylogger
 */


#ifndef _MOUSEEVENT_H
#define _MOUSEEVENT_H

#include "AEvent.h"


class __declspec(dllexport)  MouseEvent: public AEvent {
public: 
   MouseEvent(const int virtualKeyCode, const int repeatCount, const char scanCode, const bool isExtend, const bool isAlt, const bool prevKeyState, const bool transState, const std::chrono::milliseconds & time, const t_Context context);
};

#endif //_MOUSEEVENT_H