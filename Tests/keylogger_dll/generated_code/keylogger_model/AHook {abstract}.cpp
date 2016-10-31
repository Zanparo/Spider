/**
 * Project Keylogger
 */


#include "AHook {abstract}.h"

/**
 * AHook {abstract} implementation
 */


/**
 * @param HookObserver&
 */
void AHook {abstract}::AHook(void HookObserver&) {

}

/**
 * Encapsulate methods to set a hook process
 * 
 * @return bool
 */
virtual bool AHook {abstract}::setHook() {
    return false;
}

/**
 * Return the HINSTANCE 
 * @return HINSTANCE &
 */
HINSTANCE & AHook {abstract}::getHinstance() {
    return null;
}

/**
 * Notify the HookObserver _observer that a callback have been called.
 * @param int
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void AHook {abstract}::notify(void int, void LPARAM, void WPARAM) {
    return;
}

/**
 * @return bool
 */
bool AHook {abstract}::unsetHook() {
    return false;
}