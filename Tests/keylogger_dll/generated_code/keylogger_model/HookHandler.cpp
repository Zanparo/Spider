/**
 *						Project Keylogger
 */

#include				"HookHandler.h"

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
const bool HookHandler::AddHook(AHook* hook) {
   _hooks.push_back(hook);
   return true;
}

/**
 * Remove the AHook& paramater from the hook list contained by the HookHandler
 * 
 * @param const AHook&
 * @return bool
 */
const bool HookHandler::RemoveHook(AHook* hook) {
	_hooks.erase(hook);
    return false;
}