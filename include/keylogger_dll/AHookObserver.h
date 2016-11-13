#pragma once

#include		"keylogger_dll\IHookObserver.h"
#include		"keylogger_dll\EventManager.h"

class AHookObserver : public IHookObserver
{
public:
	AHookObserver(const EventManager&);
	~AHookObserver();

	void			update(const WPARAM, const LPARAM) const;

protected:
	const EventManager&		_eventManager;
	bool					_isMouse;

};

