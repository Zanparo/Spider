// Tester.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "DataHandler.hpp"
#include <stdlib.h>
#include "Tester.h"

int main(int argc, char *argv[]) {
	DataHandler dh;
	t_Mess *mess = (t_Mess*)malloc(sizeof(t_Mess) + 40);
	mess->_id = 1;
	mess->_next = false;
	mess->_size = 10;
	mess->_status = 1;
	std::string msgtext = "HelloWorld";
	for (int i = 0; i < msgtext.length(); i++) {
		mess->_data[i] = msgtext[i];
	}
	dh.parser(*mess);
}