#include <glad\glad.h>
#include <cassert>
#include <iostream>

#include "RenderMesh.h"
#include "maths\Matrix4x4.h"
#include "rendering\VertexBuffer.h"

namespace wicked
{
	RenderMesh::RenderMesh(GameObject* _gameObject)
		: vertexArray()
	{
		gameObject = _gameObject;
		init();
	}

	void RenderMesh::init()
	{
		assert(gameObject->mesh.position.size() > 0);
		vertexBufferPosition = new render::VertexBuffer(gameObject->mesh.position.size() * sizeof(maths::Vector3), &gameObject->mesh.position[0]);
		vertexBufferPosition->bind();
		vertexArray.bind();
		vertexArray.attributes(0, 3, 0, nullptr);

		if (gameObject->mesh.uv.size() > 0)
		{
			vertexBufferUV = new render::VertexBuffer(gameObject->mesh.uv.size() * sizeof(maths::Vector2), &gameObject->mesh.uv[0]);
			vertexBufferUV->bind();
			vertexArray.bind();
			vertexArray.attributes(1, 2, 0, nullptr);
		}

		if (gameObject->mesh.normal.size() > 0)
		{
			vertexBufferNormal = new render::VertexBuffer(gameObject->mesh.normal.size() * sizeof(maths::Vector3), &gameObject->mesh.normal[0]);
			vertexBufferNormal->bind();
			vertexArray.bind();
			vertexArray.attributes(2, 3, 0, nullptr);
		}
	}

	void RenderMesh::draw()
	{
		maths::Matrix4x4 model;
		model = maths::Matrix4x4::translate(model, gameObject->position);
		maths::Matrix4x4 projection;
		projection = maths::Matrix4x4::ortho(-10, 10, -10, 10, -10, 10);
		
		gameObject->shader.use();
		gameObject->shader.setMatrix4x4("model", model, false);
		gameObject->shader.setMatrix4x4("projection", projection, false);
		vertexArray.bind();
		glDrawArrays(GL_TRIANGLES, 0, gameObject->mesh.position.size());
	}
}