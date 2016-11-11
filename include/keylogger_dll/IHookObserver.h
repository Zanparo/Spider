#pragma once

#include					<Windows.h>

class IHookObserver {
	
	public:

	virtual ~IHookObserver() {};
	virtual void update(const WPARAM, const LPARAM) const = 0 {};
};