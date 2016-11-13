#ifndef	WORKQUEUE_H_
# define WORKQUEUE_H_

# include <queue>
# include "workQueueManager.h"

///////////////////////////////////////////////////
// WorkQueue
///////////////////////////////////////////////////

typedef std::queue<void *> Queue;

class WorkQueue : public AWorkQueue {

public:

	WorkQueue();

	void	push(void *);
	bool	tryPush(void *);
	void	*tryPull();
	void	*pull();

};

#endif /* !WORKQUEUE_H_ */
