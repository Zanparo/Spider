// TestInfoClient.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "InfoClient.hpp"

int main()
{
	InfoClient instance;
	std::map<InfoClient::InfoType, std::string> output;
	output = instance.routine();
	for (auto i : output) {
		std::cout << i.first << " has value " << i.second << std::endl;
	}
    return 0;
}

