#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>
#include "maths\Vector3.h"
#include "Mesh.h"
#include "Shader.h"
#include "BoxCollider.h"

namespace wicked
{
	class BoxCollider;
	class GameObject
	{
	public:
		std::string tag;
		maths::Vector3 position;
		Mesh mesh;
		Shader shader;
		BoxCollider boxCollider;
	private:
		static std::vector<GameObject*> gameObjects;
		
	public:
		GameObject();
		virtual void Start();
		virtual void Update();
		virtual void CollisionEnter(const BoxCollider& object);
	private:
		static void CheckCollision(GameObject* gameObject1, GameObject* gameObject2);

		friend class Application;
	};
}

#endif