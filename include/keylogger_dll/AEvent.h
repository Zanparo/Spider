/**
 * Project Keylogger
 */

#ifndef									_AEVENT_H
#define									_AEVENT_H

#include								<Windows.h>
#include								<chrono>
#include								<iostream>

#include								"Context.h"

class									AEvent {

public: 
    
    AEvent(const int, const int, const char, const bool, const bool, const bool, const bool, const t_Context);
	AEvent(const int, const t_Context);
	~AEvent();
	void						describe() const;

    const int							getVirtualKeyCode() const;
    const int							getRepeatCount() const;    
    const int							getScanCode() const;
    const bool							isExtend() const;    
    const bool							isAlt() const;    
    const bool							getPrevKeyState() const;
    const bool							getTransState() const;
    const t_Context						getContext() const;
	const bool							isMouse() const;

protected: 

    const int							_virtualKeyCode = 0;
    const int							_repeatCount = 0;
    const char							_scanCode = 0;
	const bool							_isMouse;
    const bool							_isExtend = false;
    const bool							_alt = false;
    const bool							_prevKeyState = false;
    const bool							_transState = false;
	const int							_hitTestCode = 0;
	const t_Context						_context;
};

#endif //_AEVENT_H