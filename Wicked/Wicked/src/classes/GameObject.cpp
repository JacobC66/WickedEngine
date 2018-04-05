#include "GameObject.h"

#include <iostream>

namespace wicked
{
	std::vector<GameObject*> GameObject::gameObjects{};

	GameObject::GameObject()
	{
		gameObjects.push_back(this);
		boxCollider.gameObject = this;
	}

	void GameObject::CheckCollision(GameObject* gameObject1, GameObject* gameObject2)
	{
		bool xCollision
		(
			((gameObject1->boxCollider.position.x + gameObject1->boxCollider.size.x) >= gameObject2->boxCollider.position.x 
			&&
			(gameObject2->boxCollider.position.x + gameObject2->boxCollider.size.x) >= gameObject1->boxCollider.position.x)
			||
			((gameObject1->boxCollider.position.x - gameObject1->boxCollider.size.x) <= gameObject2->boxCollider.position.x
			&&
			(gameObject2->boxCollider.position.x - gameObject2->boxCollider.size.x) <= gameObject1->boxCollider.position.x)
		);

		bool yCollision
		(
			((gameObject1->boxCollider.position.y + gameObject1->boxCollider.size.y) >= gameObject2->boxCollider.position.y
			&&
			(gameObject2->boxCollider.position.y + gameObject2->boxCollider.size.y) >= gameObject1->boxCollider.position.y)
			||
			((gameObject1->boxCollider.position.y - gameObject1->boxCollider.size.y) <= gameObject2->boxCollider.position.y
			&&
			(gameObject2->boxCollider.position.y - gameObject2->boxCollider.size.y) <= gameObject1->boxCollider.position.y)
		);

		if(xCollision && yCollision)
			gameObject1->CollisionEnter(gameObject2->boxCollider);
	}

	void wicked::GameObject::Start()
	{
		// VIRTUAL
	}

	void wicked::GameObject::Update()
	{
		// VIRTUAL
	}

	void GameObject::CollisionEnter(const BoxCollider& object)
	{
		// VIRTUAL
	}
}