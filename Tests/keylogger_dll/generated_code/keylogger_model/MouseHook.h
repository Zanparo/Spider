/**
 * Project Keylogger
 */


#ifndef _MOUSEHOOK_H
#define _MOUSEHOOK_H

#include "AHook {abstract}.h"


class MouseHook: public AHook {abstract} {
public: 
    
    void MouseHook();
    
    bool setHook();
    
    /**
     * @param int
     * @param LPARAM
     * @param WPARAM
     */
    static LRESULT CALLBACK mousehook(void int, void LPARAM, void WPARAM);
};

#endif //_MOUSEHOOK_H