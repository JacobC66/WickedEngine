#include <glad\glad.h>
#include <cassert>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "RenderMesh.h"
#include "maths\Matrix4x4.h"
#include "GameObject.h"

namespace wicked
{
	RenderMesh::RenderMesh(const Mesh& mesh, const Shader& shader)
		: m_mesh(mesh),
		m_shader(shader)
	{
		init();
	}

	RenderMesh::~RenderMesh()
	{
		glDeleteVertexArrays(1, &m_VAO);
	}

	void RenderMesh::init()
	{
		assert(m_mesh.position.size() > 0);

		unsigned int pVBO;
		glGenBuffers(1, &pVBO);
		glBindBuffer(GL_ARRAY_BUFFER, pVBO);
		glBufferData(GL_ARRAY_BUFFER, m_mesh.position.size() * sizeof(maths::Vector3), &m_mesh.position[0], GL_STATIC_DRAW);

		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		glEnableVertexAttribArray(0);
	}

	void RenderMesh::draw()
	{
		maths::Matrix4x4 model;
		model = maths::Matrix4x4::translate(model, maths::Vector3(0.0f, 0.0f, 0.0f));
		maths::Vector4 v(1.0f, 0.0f, 0.0f, 1.0f);

		m_shader.use();
		m_shader.setVector4("color", v);
		m_shader.setMatrix4x4("model", model, false);
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, m_mesh.position.size());
	}
}