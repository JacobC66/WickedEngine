#include "GameObject.h"
#include "Transform.h"

namespace wicked
{
	GameObject::GameObject()
		: Object("GameObject " + std::to_string(Object::s_id))
	{
		transform = new Transform(typeid(Transform).raw_name());
		transform->gameObject = this;
		component.push_back(transform);
	}

	GameObject::GameObject(std::string name)
		: Object(name)
	{
		transform = new Transform(typeid(Transform).raw_name());
		transform->gameObject = this;
		component.push_back(transform);
	}

	GameObject::~GameObject()
	{
		for (size_t i = 0; i < component.size(); i++)
		{
			delete component[i];
		}
	}

	void GameObject::setName(const std::string& name)
	{
		Object::setName(name);
	}

	const std::string& GameObject::getName() const
	{
		return Object::getName();
	}
}
