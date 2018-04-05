#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

namespace wicked
{
	namespace render
	{
		class VertexBuffer
		{
		private:
			unsigned int m_VBO;

		public:
			VertexBuffer(size_t size, void* data);
			void bind();
			void unbind();
			~VertexBuffer();
		};
	}
}

#endif