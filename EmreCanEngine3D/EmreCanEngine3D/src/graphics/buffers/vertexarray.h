#pragma once

#include <vector>
#include <GL/glew.h>
#include <CustomTypes.h>

#include "buffer.h"

namespace Can
{
	namespace Graphics
	{
		class VertexArray
		{
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffers(Buffer* buffer, GLuint index);

			void bind() const;
			void unbind() const;
		};
	}
}
