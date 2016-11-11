#include "WorkQueue.h"

WorkQueue::WorkQueue() {
	usage = true;
}

WorkQueue::~WorkQueue() {
}

void		WorkQueue::setUsage(bool c) {
	if (c == false) {
		cond_v.notify_all();
	}
	usage = c;
}

bool		WorkQueue::getUsage() {
	return (usage);
}

void		WorkQueue::add_elem(void *item) {
	std::unique_lock<std::mutex> lck(q_mtx);
	wqueue.push_back(item);
	cond_v.notify_one();
}

void*		WorkQueue::pop_elem() {
	std::unique_lock<std::mutex> lck(q_mtx);

	if (wqueue.size() == 0)
		cond_v.wait(lck);
	if (getUsage() == false)
		return (NULL);
	void* item = wqueue.front();
	wqueue.pop_front();
	return (item);
}

int		WorkQueue::getSize() {
	q_mtx.lock();
	int	size = wqueue.size();
	q_mtx.unlock();
	return (size);
}
