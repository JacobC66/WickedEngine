#ifndef MESH_H
#define MESH_H

#include <vector>
#include "maths\Vector2.h"
#include "maths\Vector3.h"

namespace wicked
{
	class Mesh
	{
	public:
		struct
		{
			std::vector<maths::Vector3> position{0};
			std::vector<maths::Vector2> uv{0};
			std::vector<maths::Vector3> normal{0};
		};

	public:
		Mesh();
		Mesh(const Mesh& mesh);
	};
}

#endif