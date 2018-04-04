#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

namespace wicked
{
	class Application
	{
	public:
		Window window;

	public:
		Application(int width, int height, const char* name);
		void run();
	};
}

#endif