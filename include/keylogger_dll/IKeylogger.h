#ifndef IKEYLOGGER_H_
# define IKEYLOGGER_H_

#include <vector>

#include "AEvent.h"
#include "WorkQueue.h"
#include "DLLoader\DLDictionary.h"

class IKeylogger {
	public:
	virtual ~IKeylogger() {}

	virtual bool				init() = 0;
	virtual bool				run() = 0;
	virtual bool				stop() = 0;
	virtual bool				kill() = 0;
	virtual bool				pushToQueue(const AEvent*) = 0;
};

typedef IKeylogger* (*_instantiate)(WorkQueue &);

#endif
