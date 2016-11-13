#include "CWMutex.h"
#include "workQueue.h"

///////////////////////////////////////////////////
// Mutex
///////////////////////////////////////////////////

bool	CWMutex::lock()
{
	this->mutex.lock();
	return (true);
}

bool	CWMutex::unlock()
{
	this->mutex.unlock();
	return (true);
}

bool	CWMutex::trylock()
{
	return (this->mutex.try_lock());
}