#ifndef INPUT_H
#define INPUT_H

#include "Window.h"

namespace wicked
{
	class Input
	{
	public:
		enum KeyCode
		{
		};

	public:
		static int getAxis(const char* axis);
		static bool getKey(KeyCode key);
	};
}

#endif