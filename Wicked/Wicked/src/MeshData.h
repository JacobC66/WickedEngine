#ifndef MESHDATA_H
#define MESHDATA_H

#include "Mesh.h"
#include "Component.h"

namespace wicked
{
	class MeshData
		: public Component
	{
	public:
		Mesh mesh;

	public:
		MeshData();
		MeshData(const std::string& name);
		virtual void setName(const std::string& name) override;
		virtual const std::string& getName() const override;
	};
}

#endif