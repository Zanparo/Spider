/**
 * Project Keylogger
 */


#ifndef _MOUSEEVENT_H
#define _MOUSEEVENT_H

#include "AEvent.h"


class  MouseEvent: public AEvent {
public: 
   MouseEvent(const int, const t_Context);
   ~MouseEvent();
   void				describe() const;

};

#endif //_MOUSEEVENT_H