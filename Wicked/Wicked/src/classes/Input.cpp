#include "Input.h"

namespace wicked
{
	int wicked::Input::getAxis(const char* axis)
	{
		if (axis == "Horizontal")
		{
			if (glfwGetKey(Window::currentWindow, GLFW_KEY_D) == GLFW_PRESS ||
				glfwGetKey(Window::currentWindow, GLFW_KEY_RIGHT) == GLFW_PRESS)
				return 1;
			else if (glfwGetKey(Window::currentWindow, GLFW_KEY_A) == GLFW_PRESS ||
				glfwGetKey(Window::currentWindow, GLFW_KEY_LEFT) == GLFW_PRESS)
				return -1;
		}
		else if (axis == "Vertical")
		{
			if (glfwGetKey(Window::currentWindow, GLFW_KEY_W) == GLFW_PRESS ||
				glfwGetKey(Window::currentWindow, GLFW_KEY_UP) == GLFW_PRESS)
				return 1;
			else if (glfwGetKey(Window::currentWindow, GLFW_KEY_S) == GLFW_PRESS ||
				glfwGetKey(Window::currentWindow, GLFW_KEY_DOWN) == GLFW_PRESS)
				return -1;
		}
		return 0;
	}
}