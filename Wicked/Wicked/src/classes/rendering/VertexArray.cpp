#include <glad\glad.h>
#include "VertexArray.h"

namespace wicked
{
	namespace render
	{
		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_VAO);
			glBindVertexArray(m_VAO);
		}

		void wicked::render::VertexArray::attributes(unsigned int index, unsigned int size, unsigned int stride, const void* offset)
		{
			glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, offset);
			glEnableVertexAttribArray(index);
		}

		void wicked::render::VertexArray::bind()
		{
			glBindVertexArray(m_VAO);
		}

		void wicked::render::VertexArray::unbind()
		{
			glBindVertexArray(0);
		}

		wicked::render::VertexArray::~VertexArray()
		{
			glDeleteVertexArrays(1, &m_VAO);
		}
	}
}