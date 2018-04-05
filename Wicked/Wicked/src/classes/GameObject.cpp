#include "GameObject.h"

#include <iostream>

namespace wicked
{
	std::vector<GameObject*> GameObject::gameObjects{};

	GameObject::GameObject()
	{
		gameObjects.push_back(this);
	}

	void wicked::GameObject::Start()
	{
		// VIRTUAL
	}

	void wicked::GameObject::Update()
	{
		// VIRTUAL
	}
}