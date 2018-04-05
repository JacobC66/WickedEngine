#include <glad\glad.h>
#include <iostream>
#include "Window.h"

namespace wicked
{
	GLFWwindow* Window::currentWindow{ nullptr };

	Window::Window(int width, int height, const char * name)
		: m_width{ width },
		m_height{ height },
		m_name{ name },
		m_buffersActivated{0}
	{
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::init()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	bool Window::createWindow()
	{
		m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
		if(!m_window)
			return false;
		glfwMakeContextCurrent(m_window);
		currentWindow = m_window;
		return true;
	}

	bool Window::initOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			return false;
		return true;
	}

	bool Window::close()
	{
		return glfwWindowShouldClose(m_window);
	}

	void Window::enableBuffers(Buffers buffer)
	{
		switch (buffer)
		{
		case Window::DEPTH:
			glEnable(GL_DEPTH_TEST);
			m_buffersActivated = 1;
			break;
		case Window::STENCIL:
			glEnable(GL_STENCIL_TEST);
			m_buffersActivated = 2;
			break;
		case Window::ALL:
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_STENCIL_TEST);
			m_buffersActivated = 3;
			break;
		}
	}

	void Window::color(const maths::Vector4 & vColor)
	{
		glClearColor(vColor.r, vColor.g, vColor.b, vColor.a);
	}

	void Window::updateBufers()
	{
		if (m_buffersActivated == 0)
			glClear(GL_COLOR_BUFFER_BIT);
		else if (m_buffersActivated == 1)
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		else if (m_buffersActivated == 2)
			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		else
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

	void Window::events()
	{
		glfwPollEvents();
	}
}