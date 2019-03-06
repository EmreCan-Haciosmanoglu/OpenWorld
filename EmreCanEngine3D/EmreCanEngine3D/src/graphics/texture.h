#pragma once

#include <string>
#include <GL/glew.h>
#include "../utils/imageload.h"
#include <FreeImage.h> 

namespace Can
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
			
			inline const GLuint getID() const { return m_TID; }
			inline const GLsizei getWidth() const { return m_Width; }
			inline const GLsizei getHeight() const { return m_Height; }
		private:
			GLuint load();
		};
	}
}