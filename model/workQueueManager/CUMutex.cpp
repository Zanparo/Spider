#include "CUMutex.h"
#include "workQueue.h"

///////////////////////////////////////////////////
// Mutex
///////////////////////////////////////////////////

bool	CUMutex::lock()
{
	this->mutex.lock();
	return (true);
}

bool	CUMutex::unlock()
{
	this->mutex.unlock();
	return (true);
}

bool	CUMutex::trylock()
{
	return (this->mutex.try_lock());
}
