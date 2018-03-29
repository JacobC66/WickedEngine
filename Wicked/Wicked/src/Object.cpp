#include "Object.h"

namespace wicked
{
	size_t Object::s_id = 0;

	Object::Object()
		: m_id{ ++s_id }
	{
	}

	Object::Object(std::string name)
		: m_name{ name }, m_id{ ++s_id }
	{
	}

	size_t Object::getId() const
	{
		return m_id;
	}

	void Object::setName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& Object::getName() const
	{
		return m_name;
	}
}
