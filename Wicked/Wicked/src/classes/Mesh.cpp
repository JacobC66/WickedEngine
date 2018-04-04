#include "Mesh.h"

namespace wicked
{
	wicked::Mesh::Mesh()
	{
	}

	wicked::Mesh::Mesh(const Mesh & mesh)
		: position(mesh.position)
	{
	}
}