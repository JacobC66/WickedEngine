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
		render::VertexBuffer vertexBuffer;
		render::VertexArray vertexArray;
		GameObject* gameObject;

	public:
		RenderMesh(GameObject* _gameObject);
		void init();
		void draw();
	};
}

#endif