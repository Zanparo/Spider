#ifndef	CUMUTEX_H_
# define CUMUTEX_H_

# include <list>
# include <strsafe.h>
# include <windows.h>
# include <tchar.h>
# include <mutex>
# include "workQueueManager.h"

///////////////////////////////////////////////////
// Mutex
///////////////////////////////////////////////////

class CUMutex : public IMutex {

	std::mutex	mutex;

public:

	bool	lock();
	bool	unlock();
	bool	trylock();

};

#endif /* !CWMUTEX_H_ */
