#ifndef COMPONENT_H
#define COMPONENT_H

#include <cassert>
#include "Object.h"
#include "GameObject.h"

namespace wicked
{
	class GameObject;

	class Component
		: public Object
	{
	public:
		GameObject* gameObject;

	public:
		Component();
		Component(std::string);
		virtual void setName(const std::string& name) override;
		virtual const std::string& getName() const override;
	};
}

#endif