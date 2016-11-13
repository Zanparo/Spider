#ifndef	CWMUTEX_H_
# define CWMUTEX_H_

# include <list>
# include <strsafe.h>
# include <windows.h>
# include <tchar.h>
# include <mutex>
# include <condition_variable>
# include "workQueueManager.h"

///////////////////////////////////////////////////
// Mutex
///////////////////////////////////////////////////

class CWMutex : public IMutex {

	std::mutex	mutex;

public:

	bool	lock();
	bool	unlock();
	bool	trylock();

};

#endif /* !CWMUTEX_H_ */
