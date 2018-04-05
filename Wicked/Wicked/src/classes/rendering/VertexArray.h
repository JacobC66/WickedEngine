#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

namespace wicked
{
	namespace render
	{
		class VertexArray
		{
		private:
			unsigned int m_VAO;

		public:
			VertexArray();
			void attributes(unsigned int index, unsigned int size, unsigned int stride, const void* offset);
			void bind();
			void unbind();
			~VertexArray();
		};
	}
}

#endif