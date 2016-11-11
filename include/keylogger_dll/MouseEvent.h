/**
 * Project Keylogger
 */


#ifndef _MOUSEEVENT_H
#define _MOUSEEVENT_H

#include "AEvent.h"


class  MouseEvent: public AEvent {
public: 
   MouseEvent(const int virtualKeyCode, const int repeatCount, const char scanCode, const bool isExtend, const bool isAlt, const bool prevKeyState, const bool transState, const t_Context context);
};

#endif //_MOUSEEVENT_H