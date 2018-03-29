#include "Transform.h"

namespace wicked
{
	Transform::Transform()
		: Component(), position(0.0f, 0.0f, 0.0f)
	{
	}

	Transform::Transform(const std::string& name)
		: Component(name), position(0.0f, 0.0f, 0.0f)
	{
	}

	void Transform::setName(const std::string& name)
	{
		assert(gameObject);
		gameObject->setName(name);
	}

	const std::string& Transform::getName() const
	{
		assert(gameObject);
		return gameObject->getName();
	}

	void Transform::translate(const maths::Vector3 & translation)
	{
		position += translation;
	}
}
