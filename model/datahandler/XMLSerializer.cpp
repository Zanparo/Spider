#include "XMLSerializer.h"
#include "AEvent.h"
#include "Analyser.h"

XMLSerializer::XMLSerializer()
{
}

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

std::string			XMLSerializer::serializeEvent(std::string windowName, std::string code)
{
	XMLTree			tree;

	tree["WINDOW_TITLE"] = windowName;
	tree["CODE"] = code;
	return (this->createXML(tree));
}
