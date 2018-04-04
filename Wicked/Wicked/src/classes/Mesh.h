#ifndef MESH_H
#define MESH_H

#include <vector>
#include "maths\Vector3.h"

namespace wicked
{
	class Mesh
	{
	public:
		struct
		{
			std::vector<maths::Vector3> position;
			//std::vector<maths::Vector3> normal;
		};

	public:
		Mesh();
		Mesh(const Mesh& mesh);
	};
}

#endif