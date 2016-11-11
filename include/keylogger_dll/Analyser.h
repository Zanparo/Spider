/**
* Project Keylogger
*/

#ifndef									_ANALYSER_H
#define									_ANALYSER_H

#include								<iostream>
#include								<map>
#include								<Windows.h>

class Analyser
{
public:
	Analyser();
	~Analyser();

private:
	void								initMap();

private:
	std::map<int, std::string>			_translateMap;
};

#endif