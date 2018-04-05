#include <glad\glad.h>
#include "Application.h"
#include "maths\Vector4.h"

#include <iostream>
#include <vector>

#include "RenderMesh.h"
#include "Time.h"

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
				// Start
				std::vector<RenderMesh *>renderGameObject;
				for (size_t i{ 0 }; i < GameObject::gameObjects.size(); i++)
				{
					GameObject::gameObjects[i]->Start();
					renderGameObject.push_back(new RenderMesh(GameObject::gameObjects[i]));
				}

				float lastFrame = 0.0f;
				while (!window.close())
				{
					float currentFrame = static_cast<float>(glfwGetTime());
					Time::deltaTime = currentFrame - lastFrame;
					lastFrame = currentFrame;

					static maths::Vector4 color(0.5f, 0.5f, 0.5f, 1.0f);
					window.color(color);
					window.updateBufers();

					// Update
					for (size_t i{ 0 }; i < GameObject::gameObjects.size(); i++)
					{
						GameObject::gameObjects[i]->Update();
						renderGameObject[i]->draw();
					}

					window.swapBuffers();
					window.events();
				}
			}
		}
	}
}