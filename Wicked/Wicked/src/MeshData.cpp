#include <fstream>
#include <algorithm>
#include <sstream>
#include "MeshData.h"

namespace wicked
{
	MeshData::MeshData()
		: Component()
	{
	}

	MeshData::MeshData(const std::string& name)
		: Component(name)
	{
	}

	void MeshData::setName(const std::string& name)
	{
		assert(gameObject);
		gameObject->setName(name);
	}

	const std::string& MeshData::getName() const
	{
		assert(gameObject);
		return gameObject->getName();
	}
}