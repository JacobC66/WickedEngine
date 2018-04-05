#include "Mesh.h"

namespace wicked
{
	Mesh::Mesh()
	{
	}

	Mesh::Mesh(const Mesh & mesh)
		: position(mesh.position),
		uv(mesh.uv),
		normal(mesh.normal)
	{
	}
}