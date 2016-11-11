/**
 * Project Keylogger
 */


#include "keylogger_dll/KeyboardEvent.h"

/**
 * KeyboardEvent implementation
 */

/** 
 * KeyboardEvent constructor
 */
KeyboardEvent::KeyboardEvent(const int virtualKeyCode, const int repeatCount, const char scanCode, const bool isExtend, const bool isAlt, const bool prevKeyState, const bool transState, const t_Context context) : AEvent::AEvent(virtualKeyCode, repeatCount, scanCode, isExtend, isAlt, prevKeyState, transState, context)
{

}