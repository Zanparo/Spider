/**
 *						Project Keylogger
 */


#include				"MouseHook.h"

/**
 * MouseHook implementation
 */


MouseHook::MouseHook(const HookObserver& hookObserver) : AHook::AHook(hookObserver) {
}

/**
 * @return bool if hook set succeeded
 */
const bool				MouseHook::setHook() const {
    return false;
}

/**
 * @param int
 * @param LPARAM
 * @param WPARAM
 * @return LRESULT CALLBACK
 */
LRESULT CALLBACK		MouseHook::mousehook(const int code, const LPARAM lparam, const WPARAM wparam) {
    return CallNextHookEx(NULL, code, wparam, lparam);
}