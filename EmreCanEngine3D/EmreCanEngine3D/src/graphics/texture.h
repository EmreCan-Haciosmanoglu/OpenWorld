#pragma once

#include <FreeImage.h> 
#include <string>
#include <GL/glew.h>
#include "../utils/imageload.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Texture
		{
		private:
			std::string m_FileName;
			GLuint m_TID;
			GLsizei m_Width, m_Height;
		public:
			Texture(const std::string& filename);
			~Texture();
			void bind() const;
			void unbind() const;

			inline const GLsizei getWidth() const { return m_Width; }
			inline const GLsizei getHeight() const { return m_Height; }
		private:
			GLuint load();
		};
	}
}