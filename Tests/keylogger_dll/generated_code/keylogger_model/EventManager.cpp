/**
 * Project Keylogger
 */
#include				"EventManager.h"


/**
 * @param Keylogger&
 */
EventManager::EventManager(const Keylogger& keylogger) : _keylogger(keylogger){
}

EventManager::~EventManager()
{
}

/**
 * Call the Event Factory to create an event depending on parameters. 
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void					EventManager::handleEvent(const LPARAM lparam, const WPARAM wparam) {
    return;
}