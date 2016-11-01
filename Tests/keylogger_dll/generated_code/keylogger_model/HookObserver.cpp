/**
 *						Project Keylogger
 */


#include				"HookObserver.h"

/**
 * HookObserver implementation
 */


/**
 * @param EventManager&
 */
HookObserver::HookObserver(EventManager& eventManager) : _eventManager(eventManager) {
}

/**
 * update must notify the EventManager that an event should be created. To do this, call 
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void						HookObserver::update(const LPARAM lparam, const WPARAM wparam) {
    return;
}