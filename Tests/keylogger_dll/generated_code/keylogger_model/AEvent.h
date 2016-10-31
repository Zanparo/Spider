/**
 * Project Keylogger
 */


#ifndef _AEVENT_H
#define _AEVENT_H

class AEvent {
public: 
    
    /**
     * @param LPARAM
     * @param WPARAM
     */
    void AEvent(void LPARAM, void WPARAM);
    
    int getVirtualKeyCode();
    
    int getRepeatCount();
    
    int getScanCode();
    
    bool isExtend();
    
    bool isAlt();
    
    bool getPrevKeyState();
    
    bool getTransState();
    
    time getTime();
    
    string getWindowTitle();
protected: 
    int _virtualKeyCode;
    int _repeatCount;
    char _scanCode;
    bool _isExtend;
    bool _alt;
    bool _prevKeyState;
    bool _transState;
    time _time;
    string _windowTitle;
};

#endif //_AEVENT_H