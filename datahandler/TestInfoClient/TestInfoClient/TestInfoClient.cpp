// TestInfoClient.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "InfoClient.hpp"

int main() {
	InfoClient instance;
	std::map<InfoClient::InfoType, std::string> output;
	output = instance.routine();
	char *targetHistory;
	int historysize;
	historysize = instance.getHistory(&targetHistory);
	for (auto i : output) {
		std::cout << i.first << " has value " << i.second << std::endl;
	}
	std::cout << "History loaded: size : " << historysize << std::endl;
	char *sam;
	int samsize = instance.getSAMHive(&sam);
	std::cout << "SAM hive : Size: " << samsize << std::endl;
	std::cout << std::endl;
	return 0;
}