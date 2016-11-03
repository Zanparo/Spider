#include <iostream>
#include "client.h"

int						main(int ac, char **av)
{
	try {
		clientController	c;
		return c.mainAction(ac, av);
	}
	catch (DLibraryException &err) {
		std::cerr << err.what() << std::endl;
	}
	return (1);
}
