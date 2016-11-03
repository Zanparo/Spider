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
    
    AEvent(const int, const int, const char, const bool, const bool, const bool, const bool, const std::chrono::milliseconds&, const t_Context);
    const int							getVirtualKeyCode() const;
    const int							getRepeatCount() const;    
    const int							getScanCode() const;
    const bool							isExtend() const;    
    const bool							isAlt() const;    
    const bool							getPrevKeyState() const;
    const bool							getTransState() const;
    const std::chrono::milliseconds		getTime() const;
    const t_Context						getContext() const;

protected: 

    const int							_virtualKeyCode;
    const int							_repeatCount;
    const char							_scanCode;
    const bool							_isExtend;
    const bool							_alt;
    const bool							_prevKeyState;
    const bool							_transState;
    const std::chrono::milliseconds		_time;
	const t_Context						_context;
};

#endif //_AEVENT_H