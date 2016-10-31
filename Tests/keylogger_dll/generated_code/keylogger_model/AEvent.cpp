/**
 * Project Keylogger
 */


#include "AEvent.h"

/**
 * AEvent implementation
 */


/**
 * @param LPARAM
 * @param WPARAM
 */
void AEvent::AEvent(void LPARAM, void WPARAM) {

}

/**
 * @return int
 */
int AEvent::getVirtualKeyCode() {
    return 0;
}

/**
 * @return int
 */
int AEvent::getRepeatCount() {
    return 0;
}

/**
 * @return int
 */
int AEvent::getScanCode() {
    return 0;
}

/**
 * @return bool
 */
bool AEvent::isExtend() {
    return false;
}

/**
 * @return bool
 */
bool AEvent::isAlt() {
    return false;
}

/**
 * @return bool
 */
bool AEvent::getPrevKeyState() {
    return false;
}

/**
 * @return bool
 */
bool AEvent::getTransState() {
    return false;
}

/**
 * @return time
 */
time AEvent::getTime() {
    return null;
}

/**
 * @return string
 */
string AEvent::getWindowTitle() {
    return "";
}