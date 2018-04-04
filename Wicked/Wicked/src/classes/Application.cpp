#include <glad\glad.h>
#include "Application.h"
#include "maths\Vector4.h"
#include "GameObject.h"

#include <iostream>

#include "Shader.h"

namespace wicked
{
	Application::Application(int width, int height, const char* name)
		: window(width, height, name)
	{
		window.init();
	}

	void Application::run()
	{
		if (window.createWindow())
		{
			if (window.initOpenGL())
			{	
				/*Shader shader(svShader, sfShader);
				std::vector<maths::Vector3> vertex
				{
					maths::Vector3(-0.5f, -0.5f, 0.0),
					maths::Vector3(0.5f, -0.5f, 0.0f),
					maths::Vector3(0.0f, 0.5f, 0.0f)
				};
				Mesh mesh;
				mesh.position = vertex;
				RenderMesh rM(mesh, shader);*/

				// Start

				while (!window.close())
				{
					static maths::Vector4 color(0.5f, 0.5f, 0.5f, 1.0f);
					window.color(color);
					window.updateBufers();

					// Update

					window.swapBuffers();
					window.events();
				}
			}
		}
	}
}