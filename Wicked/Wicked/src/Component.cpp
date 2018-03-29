#include "Component.h"

namespace wicked
{
	Component::Component()
		: Object("NULL")
	{
		gameObject = nullptr;
	}

	Component::Component(std::string name)
		: Object(name)
	{
		gameObject = nullptr;
	}

	void Component::setName(const std::string& name)
	{
		Object::setName(name);
	}

	const std::string& Component::getName() const
	{
		return Object::getName();
	}
}
