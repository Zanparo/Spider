/**
 *						Project Keylogger
 */


#include				"keylogger_dll/MouseHook.h"

/**
 * MouseHook implementation
 */


MouseHook::MouseHook(const HookObserver& hookObserver) : AHook::AHook(hookObserver) {
}

/**
 * @return bool if hook set succeeded
 */
const bool				MouseHook::setHook() {
	if ((_hHook = SetWindowsHookEx(WH_MOUSE, &mousehook, NULL, 0)) == NULL)
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
	std::cout << "mousehook called" << std::endl;
    return CallNextHookEx(NULL, code, wParam, lParam);
}