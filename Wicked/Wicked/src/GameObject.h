#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Object.h"
#include "Component.h"

namespace wicked
{
	class Component;
	class Transform;

	class GameObject
		: public Object
	{
	public:
		Transform* transform;
	private:
		std::vector<Component*> component;

	public:
		GameObject();
		GameObject(std::string name);
		~GameObject();
		virtual void setName(const std::string& name) override;
		virtual const std::string& getName() const override;
		template <typename T>
		Component* addComponent();
		template <typename T>
		Component* getComponent();
	};

	template<typename T>
	Component* GameObject::addComponent()
	{
		for (size_t i = 0; i < component.size(); i++)
		{
			if (component[i]->Component::getName() == typeid(T).raw_name())
				return nullptr;
		}
		T* comp = new T(typeid(T).raw_name());
		comp->gameObject = this;
		component.push_back(comp);
		return comp;
	}

	template<typename T>
	Component* GameObject::getComponent()
	{
		for (size_t i = 0; i < component.size(); i++)
		{
			if (component[i]->Component::getName() == typeid(T).raw_name())
				return component[i];
		}
		return nullptr;
	}
}

#endif