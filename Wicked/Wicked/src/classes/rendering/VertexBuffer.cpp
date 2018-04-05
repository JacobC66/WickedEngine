#include <glad\glad.h>
#include <iostream>
#include "VertexBuffer.h"

namespace wicked
{
	namespace render
	{
		VertexBuffer::VertexBuffer(size_t size, void* data)
		{
			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		}

		void VertexBuffer::bind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		}

		void VertexBuffer::unbind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		VertexBuffer::~VertexBuffer()
		{
			glDeleteBuffers(1, &m_VBO);
		}
	}
}