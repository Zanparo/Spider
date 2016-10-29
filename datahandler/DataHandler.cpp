#include "DataHandler.hpp"

DataHandler::DataHandler() {
	std::cout << "DataHandler" << std::endl;
}

DataHandler::~DataHandler() {

}

void	DataHandler::parser(t_Mess const& Mess) {
	for (unsigned int i = 0; i < Mess._size; i++) {
		flux << Mess._data[i];
	}
	std::cout << flux.str() << std::endl;
}

