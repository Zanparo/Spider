#ifdef __linux__
# include "CUMutex.h"
#elif _WIN32
# include "CWMutex.h"
#endif
#include "workQueue.h"

WorkQueue::WorkQueue()
{
#ifdef __linux__
	this->access = new CUMutex();
#elif _WIN32
	this->access = new CWMutex();
#endif
}

void	WorkQueue::push(void * item)
{
	this->access->lock();
	this->stack.push(item);
	this->access->unlock();
}

bool	WorkQueue::tryPush(void * item)
{
	if (!this->access->trylock())
		return (false);
	this->stack.push(item);
	this->access->unlock();
	return (true);
}

void*		WorkQueue::tryPull()
{
	void	*data = NULL;

	if (!this->access->trylock())
		return (NULL);
	if (this->stack.size())
	{
		data = this->stack.front();
		this->stack.pop();
	}
	this->access->unlock();
	return (data);
}

void*	WorkQueue::pull()
{
	void	*data = NULL;

	this->access->lock();
	if (this->stack.size())
	{
		data = this->stack.front();
		this->stack.pop();
	}
	this->access->unlock();
	return (data);
}
