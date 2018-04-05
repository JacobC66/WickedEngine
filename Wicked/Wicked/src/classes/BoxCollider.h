#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "maths\Vector3.h"

namespace wicked
{
	class GameObject;
	class BoxCollider
	{
	public:
		maths::Vector3 position;
		maths::Vector3 size;
		GameObject* gameObject;

	public:
		BoxCollider();
		BoxCollider(const maths::Vector3& _position, const maths::Vector3& _size);
		void setPosition(const maths::Vector3& _position);
		void setSize(const maths::Vector3& _size);
	};
}

#endif