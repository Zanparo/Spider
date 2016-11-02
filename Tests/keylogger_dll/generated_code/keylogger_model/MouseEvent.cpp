/**
 * Project Keylogger
 */


#include "MouseEvent.h"

/**
 * MouseEvent implementation
 */


MouseEvent::MouseEvent(const int virtualKeyCode, const int repeatCount, const char scanCode, const bool isExtend, const bool isAlt, const bool prevKeyState, const bool transState, const std::chrono::milliseconds& time, const t_Context context) : AEvent::AEvent(virtualKeyCode, repeatCount, scanCode, isExtend, isAlt, prevKeyState, transState, time, context) {
}