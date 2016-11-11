#ifndef		WORKQUEUE_HPP_
#define		WORKQUEUE_HPP_

#include <list>
#include <mutex>
#include <condition_variable>

class WorkQueue {
public:
	WorkQueue();
	~WorkQueue();

	void		add_elem(void *item);
	void		*pop_elem();
	int		getSize();
	void		setUsage(bool c);
	bool		getUsage();

private:
	std::list<void*>	wqueue;
	std::mutex	q_mtx;
	std::condition_variable	cond_v;
	std::unique_lock<std::mutex> lck;
	bool		usage;
};

#endif
