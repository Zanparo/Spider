#include <iostream>
#include "DataHandler.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	DataHandler item;
	t_Mess *mess = malloc(sizeof(t_Mess) + 40);
	mess->_data = "HelloWorld";
}