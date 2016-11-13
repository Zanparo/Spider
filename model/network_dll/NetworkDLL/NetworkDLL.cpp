// NetworkDLL.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "NetworkDLL.h"


/////////////////////////////////////////////////////
// Sources
/////////////////////////////////////////////////////

INetwork	*instanciate(int nb)
{
	if (nb == 0)
	{
		return (new clientManager());
	}
	else if (nb == 1)
	{
		return (new serverManager());
	}
	return (NULL);
}


/*void		launch()
{
	net_ = new clientManager();

	std::cout << "Je suis la" << std::endl;
	net_->init("127.0.0.1|4242");
	std::cout << "deufhdeuifh" << std::endl;
}

void		send_data(std::string)
{
	//net_->send_data(data);
	std::cout << "Je suis la" << std::endl;
}*/

void	sayHelloFrom(std::string from)
{
	std::cout << "Hello World from " << from << std::endl;
}

/////////////////////////////////////////////////////
// Get Dictionary
/////////////////////////////////////////////////////

extern "C" {
	__declspec(dllexport) Dictionary	__cdecl getDictionary(void)
	{
		Dictionary	dict = new std::map<std::string, void *>;

		// List every usefull functions out there
		//(*dict)["launch"] = (void *)&launch;
		(*dict)["instanciate"] = (INetwork *)&instanciate;
		//(*dict)["send_data"] = (void *)&send_data;
		(*dict)["sayHelloFrom"] = (void *)&sayHelloFrom;
		return (dict);
	}
}
