#pragma once

#include <vector>

#include "AEvent.h"

class IKeylogger {
	public:
	virtual ~IKeylogger() {};

	virtual bool init() = 0;
	virtual bool run() = 0;
	virtual bool stop() = 0;
	virtual bool kill() = 0;
	virtual bool pushToQueue(const AEvent*) = 0;
	virtual std::vector<AEvent*> getEvents() const = 0;
};
