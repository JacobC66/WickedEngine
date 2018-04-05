#include "BoxCollider.h"

namespace wicked
{
	BoxCollider::BoxCollider()
	{
	}

	BoxCollider::BoxCollider(const maths::Vector3& _position, const maths::Vector3& _size)
		: position(_position),
		size(_size)
	{
	}

	void BoxCollider::setPosition(const maths::Vector3& _position)
	{
		position = _position;
	}

	void BoxCollider::setSize(const maths::Vector3& _size)
	{
		size = _size;
	}
}