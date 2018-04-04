#include "GameObject.h"

#include <iostream>

namespace wicked
{
	std::vector<GameObject*> GameObject::vGameObjects{};

	GameObject::GameObject(const maths::Vector3& pos, const Mesh& mesh, const Shader& shader)
		: position(pos),
		renderMesh(mesh, shader)
	{
		renderMesh.gameObject = this;
		vGameObjects.push_back(this);
	}

	void GameObject::setPosition(const maths::Vector3 & pos)
	{
		position = pos;
	}

	void GameObject::setRenderMesh(const RenderMesh & rMesh)
	{
		//renderMesh = rMesh;
	}

	void GameObject::Start()
	{
		// VIRTUAL
	}

	void GameObject::Update()
	{
		// VIRTUAL
	}
}