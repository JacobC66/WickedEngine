#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "maths\Vector3.h"
#include "Component.h"

namespace wicked
{
	class Transform
		: public Component
	{
	public:
		maths::Vector3 forward;
		maths::Vector3 position;
		maths::Vector3 right;
		maths::Vector3 up;

	public:
		Transform();
		Transform(const std::string& name);
		virtual void setName(const std::string& name) override;
		virtual const std::string& getName() const override;
		void translate(const maths::Vector3& translation);
	};
}

#endif