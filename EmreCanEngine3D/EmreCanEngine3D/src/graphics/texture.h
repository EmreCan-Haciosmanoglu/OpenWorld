#pragma once

#include <string>
#include <iostream>
#include <GL/glew.h>
#include "../utils/imageload.h"
#include <FreeImage.h> 

namespace Can
{
	namespace Graphics
	{
		class Texture
		{
		private:
			std::string m_FileName;
			std::string m_Name;
			GLuint m_TID;
			GLsizei m_Width, m_Height;
			unsigned int m_Bits;
		public:
			Texture(const std::string& name, const std::string& filename);
			~Texture();
			void bind() const;
			void unbind() const;
			
			inline const GLuint getID() const { return m_TID; }
			inline const GLsizei getWidth() const { return m_Width; }
			inline const GLsizei getHeight() const { return m_Height; }

			inline const std::string& getName() const { return m_Name; }
			inline const std::string& getFileName() const { return m_FileName; }
		private:
			GLuint load();
		};
	}
}