#pragma once

#include				"AHookObserver.h"

class MouseHookObserver : public AHookObserver
{
public:
	MouseHookObserver(const EventManager&);
	~MouseHookObserver();
};

