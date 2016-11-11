#include "keylogger_dll\MouseHookObserver.h"



MouseHookObserver::MouseHookObserver(const EventManager& eventManager) : AHookObserver(eventManager)
{
	_isMouse = true;
}


MouseHookObserver::~MouseHookObserver()
{
}
