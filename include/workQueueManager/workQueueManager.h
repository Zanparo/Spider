#ifndef	WORKQUEUEMANAGER_H_
# define WORKQUEUEMANAGER_H_

# include <thread>
# include <mutex>
# include <queue>

///////////////////////////////////////////////////
// Mutex
///////////////////////////////////////////////////

class IMutex {
public:

	virtual bool	lock() = 0;
	virtual bool	unlock() = 0;
	virtual bool	trylock() = 0;
};


///////////////////////////////////////////////////
// WorkQueue
///////////////////////////////////////////////////

typedef std::queue<void *> QueueStack;

class IWorkQueue {

public:

	virtual void	push(void * item) = 0;
	virtual bool	tryPush(void * item) = 0;
	virtual	void	*tryPull() = 0;
	virtual	void	*pull() = 0;

};

class AWorkQueue : public IWorkQueue {

public:

	QueueStack		stack;
	IMutex			*access;

};

typedef		IWorkQueue *(*_getAWorkQueue)(void);

#endif /* !WORKQUEUEMANAGER_H_ */
