#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "maths\Vector3.h"
#include "Mesh.h"
#include "Shader.h"

namespace wicked
{
	class GameObject
	{
	public:
		maths::Vector3 position;
		Mesh mesh;
		Shader shader;
	private:
		static std::vector<GameObject*> gameObjects;
		
	public:
		GameObject();
		virtual void Start();
		virtual void Update();

		friend class Application;
	};
}

#endif