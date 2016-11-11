/**
 * Project Keylogger
 */


#include "keylogger_dll/MouseEvent.h"

/**
 * MouseEvent implementation
 */


MouseEvent::MouseEvent(const int hitTestCode, const t_Context context) : AEvent::AEvent(hitTestCode, context) {
}

MouseEvent::~MouseEvent()
{
}

void				MouseEvent::describe() const
{
	std::cout << "[MouseEvent]: hitTestCode=" << _hitTestCode << "|time=" << _context._ms << "|MousePos=" << _context._mousePos << "|Window=" << std::endl; // _context._windowTitle << std::endl;
}