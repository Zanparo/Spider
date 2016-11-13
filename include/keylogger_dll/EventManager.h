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
    void					handleMouseEvent(const WPARAM, const LPARAM) const;
	void					handleKeyboardEvent(const WPARAM, const LPARAM) const;

private:

	const struct s_Context			*updateContext() const;

private: 
    Keylogger&				_keylogger;
};

#endif //_EVENTMANAGER_H