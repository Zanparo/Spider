#include "client.h"

int						main(int ac, char *av[]) {
	clientController	controller();
	return controller->mainAction(ac, av);
}