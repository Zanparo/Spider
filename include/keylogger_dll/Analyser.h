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

private:
	std::map<int, std::string>			_translateMap;
};

#endif