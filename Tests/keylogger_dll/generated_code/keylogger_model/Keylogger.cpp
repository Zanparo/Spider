/**
 * Project Keylogger
 */

#include "Keylogger.h"
#include "KeyloggerDLL.h"

/**
 * Keylogger implementation
 */


Keylogger Keylogger::_instance = Keylogger();

Keylogger::Keylogger() : _eventManager(*(new EventManager(_instance))), _hookHandler(*(new HookHandler(_eventManager))) {
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
 * @return Keylogger&
 */
Keylogger& Keylogger::getInstance() {
    return _instance;
}

/**
 * @param AEvent*
 * @return bool
 */
bool Keylogger::pushToQueue(AEvent* event) {
    return false;
}