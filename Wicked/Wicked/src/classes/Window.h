#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW\glfw3.h>
#include "maths\Vector4.h"

namespace wicked
{
	class Window
	{
	public:
		enum Buffers
		{
			DEPTH,
			STENCIL,
			ALL
		};
	private:
		int m_width;
		int m_height;
		const char* m_name;
		GLFWwindow* m_window;
		int m_buffersActivated;

		static GLFWwindow* currentWindow;

	public:
		Window(int width, int height, const char* name);
		~Window();
		void init();
		bool createWindow();
		bool initOpenGL();
		bool close();
		void enableBuffers(Buffers buffer);
		void color(const maths::Vector4& vColor);
		void updateBufers();
		void swapBuffers();
		void events();

		friend class Input;
	};
}

#endif