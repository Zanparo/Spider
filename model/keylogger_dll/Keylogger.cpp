/**
 * Project Keylogger
 */

#include "keylogger_dll/Keylogger.h"

/**
 * Keylogger implementation
 */
Keylogger::Keylogger() : _eventManager(*(new EventManager(*this))), _hookHandler(*(new HookHandler(_eventManager))) {
}

Keylogger::~Keylogger()
{

}


/**
 * @return bool
 */
bool Keylogger::init() {
	std::cout << "init done." << std::endl;
    return true;
}

/**
 * @return void
 */
void Keylogger::run() {
    return;
}

/**
 * @return bool
 */
bool Keylogger::stop() {
    return false;
}

/**
 * @return bool
 */
bool Keylogger::kill() {
    return false;
}

/**
 * @param AEvent*
 * @return bool
 */
bool Keylogger::pushToQueue(AEvent* event) {
    return false;
}
