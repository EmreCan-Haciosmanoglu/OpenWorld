#include "texture.h"

namespace Can
{
	namespace Graphics
	{
		Texture::Texture(const std::string& name, const std::string & filename)
			: m_Name(name)
			, m_FileName(filename)
		{
			m_TID = load();
		}
		Texture::~Texture()
		{
			glDeleteTextures(1, &m_TID);
		}
		void Texture::bind() const
		{
			glBindTexture(GL_TEXTURE_2D, m_TID);
		}
		void Texture::unbind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		GLuint Texture::load()
		{
			BYTE* pixels = load_image(m_FileName.c_str(), &m_Width, &m_Height, &m_Bits);
			
			GLuint result;
			glGenTextures(1, &result);
			glBindTexture(GL_TEXTURE_2D, result);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			if (m_Bits != 24 && m_Bits != 32)
				std::cout << "Error" << std::endl;// "SPARKY_ERROR("[Texture] Unsupported image bit - depth!(%d)", m_Bits);

			GLint internalFormat = m_Bits == 32 ? GL_RGBA : GL_RGB;
			GLenum format = m_Bits == 32 ? GL_BGRA : GL_BGR;

			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, pixels);
			glBindTexture(GL_TEXTURE_2D, 0);

			delete[] pixels;

			return result;
		}
	}
}