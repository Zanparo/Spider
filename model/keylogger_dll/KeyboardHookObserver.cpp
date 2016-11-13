/**
 *						Project Keylogger
 */

#include				<iostream>
#include				"keylogger_dll/KeyboardHookObserver.h"

/**
 * HookObserver implementation
 */


/**
 * @param EventManager&
 */
KeyboardHookObserver::KeyboardHookObserver(const EventManager& eventManager) : AHookObserver::AHookObserver(eventManager) {
	_isMouse = false;
}

KeyboardHookObserver::~KeyboardHookObserver()
{
}