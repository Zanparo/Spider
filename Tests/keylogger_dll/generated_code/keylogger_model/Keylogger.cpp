/**
 * Project Keylogger
 */


#include "Keylogger.h"

/**
 * Keylogger implementation
 */


Keylogger Keylogger::_instance = Keylogger();

Keylogger::Keylogger() {

}

/**
 * @return bool
 */
bool Keylogger::init() {
    return false;
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