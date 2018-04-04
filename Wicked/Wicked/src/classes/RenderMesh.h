#ifndef RENDERMESH_H
#define RENDERMESH_H

#include "Mesh.h"
#include "Shader.h"

namespace wicked
{
	class GameObject;

	class RenderMesh
	{
	public:
		GameObject* gameObject;
	public:
		Mesh m_mesh;
		Shader m_shader;
		unsigned int m_VAO;

	public:
		RenderMesh(const Mesh& mesh, const Shader& shader);
		~RenderMesh();
		void init();
		void draw();
	};
}

#endif