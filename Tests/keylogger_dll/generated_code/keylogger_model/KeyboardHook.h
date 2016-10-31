/**
 * Project Keylogger
 */


#ifndef _KEYBOARDHOOK_H
#define _KEYBOARDHOOK_H

#include "AHook {abstract}.h"


class KeyboardHook: public AHook {abstract} {
public: 
    
    void KeyboardHook();
    
    bool setHook();
    
    /**
     * @param int
     * @param LPARAM
     * @param WPARAM
     */
    static LRESULT CALLBACK keyboardhook(void int, void LPARAM, void WPARAM);
};

#endif //_KEYBOARDHOOK_H