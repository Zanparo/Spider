#include "server.h"

int						main(int ac, char *av[]) {
	serverController	controller();
	return controller->mainAction(ac, av);
}