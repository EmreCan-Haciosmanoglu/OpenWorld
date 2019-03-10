#include "font.h"

namespace Can
{
	namespace Graphics
	{
		Font::Font(std::string name, std::string filename, unsigned int size)
			: m_Name(name)
			, m_FileName(filename)
			, m_FontSize(size)
		{
			m_FTAtlas = ftgl::texture_atlas_new(512, 512, 2);
			m_FTFont = ftgl::texture_font_new_from_file(m_FTAtlas, size, filename.c_str());
		}
		void Font::setScale(float x, float y)
		{
			m_Scale = maths::vec2(x, y);	
		}
	}
}