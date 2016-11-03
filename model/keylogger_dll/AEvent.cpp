/**
 *								Project Keylogger
 */


#include						"keylogger_dll/AEvent.h"

/**
 * AEvent implementation
 */


/**
 * Constructor of AEvent
 */
AEvent::AEvent(const int virtualKeyCode, const int repeatCount, const char scanCode, const bool isExtend, const bool isAlt, const bool prevKeyState, const bool transState, const std::chrono::milliseconds& time, const t_Context context) : _virtualKeyCode(virtualKeyCode), _repeatCount(repeatCount), _scanCode(scanCode), _isExtend(isExtend), _alt(isAlt), _prevKeyState(prevKeyState), _transState(transState), _time(time), _context(context) {
}

/**
 * @return int the virtual key code
 */
const int						AEvent::getVirtualKeyCode() const {
    return	_virtualKeyCode;
}

/**
 * @return int the repeat counter
 */
const int						AEvent::getRepeatCount() const{
    return _repeatCount;
}

/**
 * @return int the scan code
 */
const int						AEvent::getScanCode() const {
    return _scanCode;
}

/**
 * @return bool the extend value
 */
const bool						AEvent::isExtend() const {
    return _isExtend;
}

/**
 * @return bool the alt value
 */
const bool						AEvent::isAlt() const {
    return _alt;
}

/**
 * @return bool the previous key state
 */
const bool						AEvent::getPrevKeyState() const {
    return _prevKeyState;	
}							
							
/**							
 * @return bool the transition state
 */							
const bool						AEvent::getTransState() const {
    return _transState;
}

/**
 * @return std::chrono::milliseconds the recording of time
 */
const std::chrono::milliseconds	 AEvent::getTime() const{
    return _time;
}

/**
 * @return string the title of the active window
 */
const t_Context					AEvent::getContext() const {
    return _context;
}