#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

namespace wicked
{
	class Object
	{
	private:
		size_t m_id = 0;
		std::string m_name;

	public:
		static size_t s_id;

	public:
		Object();
		Object(std::string name);
		size_t getId() const;
		virtual void setName(const std::string& name);
		virtual const std::string& getName() const;
	};
}

#endif