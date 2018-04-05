#ifndef RENDERMESH_H
#define RENDERMESH_H

#include "rendering\VertexArray.h"
#include "rendering\VertexBuffer.h"
#include "GameObject.h"

namespace wicked
{
	class GameObject;

	class RenderMesh
	{
	public:
		render::VertexBuffer* vertexBufferPosition;
		render::VertexBuffer* vertexBufferUV;
		render::VertexBuffer* vertexBufferNormal;
		render::VertexArray vertexArray;
		GameObject* gameObject;

	public:
		RenderMesh(GameObject* _gameObject);
		void draw();
	private:
		void init();
	};
}

#endif