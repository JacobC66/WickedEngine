#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "maths\Vector3.h"
#include "RenderMesh.h"

namespace wicked
{
	class GameObject
	{
	public:
		maths::Vector3 position;
		RenderMesh renderMesh;
	private:
		static std::vector<GameObject*> vGameObjects;

	public:
		GameObject(const maths::Vector3& pos, const Mesh& mesh, const Shader& shader);
		void setPosition(const maths::Vector3& pos);
		void setRenderMesh(const RenderMesh& rMesh);

		virtual void Start();
		virtual void Update();

		friend class Application;
	};
}

#endif