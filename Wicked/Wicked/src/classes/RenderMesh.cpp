#include <glad\glad.h>
#include <cassert>
#include <iostream>

#include "RenderMesh.h"
#include "maths\Matrix4x4.h"
#include "rendering\VertexBuffer.h"

namespace wicked
{
	RenderMesh::RenderMesh(GameObject* _gameObject)
		: vertexBuffer(_gameObject->mesh.position.size() * sizeof(maths::Vector3), &_gameObject->mesh.position[0]),
		vertexArray()
	{
		gameObject = _gameObject;
		init();
	}

	void RenderMesh::init()
	{
		assert(gameObject->mesh.position.size() > 0);
		vertexBuffer.bind();
		vertexArray.bind();
		vertexArray.attributes(0, 3, 0, nullptr);
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