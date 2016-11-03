/**
 *							Project Keylogger
 */


#include					"keylogger_dll/KeyboardHook.h"

/**
 * KeyboardHook implementation
 */


KeyboardHook::KeyboardHook(const HookObserver& observer) : AHook::AHook(observer){
}

/**
 * @return bool true if hook set succeeded
 */
const bool						KeyboardHook::setHook() {
    return false;
}

/**
 * @param int
 * @param LPARAM
 * @param WPARAM
 * @return LRESULT CALLBACK
 */
LRESULT CALLBACK			KeyboardHook::keyboardhook(const int code, const LPARAM lparam, const WPARAM wparam) {
    return CallNextHookEx(NULL, code, lparam, wparam);
}