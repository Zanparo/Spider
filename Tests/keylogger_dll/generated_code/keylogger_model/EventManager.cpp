/**
 * Project Keylogger
 */


#include "EventManager.h"

/**
 * EventManager implementation
 */


/**
 * @param Keylogger&
 */
EventManager::EventManager(Keylogger& keylogger) {
	_keylogger = keylogger;
}

/**
 * Call the Event Factory to create an event depending on parameters. 
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void EventManager::HandleEvent(void LPARAM, void WPARAM) {
    return;
}