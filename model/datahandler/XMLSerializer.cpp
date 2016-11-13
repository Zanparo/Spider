#include "XMLSerializer.h"

std::string				XMLSerializer::createXML(XMLTree tree)
{
	XMLTree::iterator	node;
	std::string			res = std::string("");

	if (!tree.size())
		return (res);
	for (node = tree.begin(); node != tree.end(); ++node)
	{
		res += "<";
		res += (*node).first;
		res += ">";
		res += (*node).second;
		res += "</";
		res += (*node).first;
		res += ">";
	}
	return (res);
}
