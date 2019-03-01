#pragma once

#include <string>
#include "../../ext/freetype-gl/freetype-gl.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Font
		{
		public:
			Font(std::string name, std::string filename, unsigned int size);

			inline const ftgl::texture_atlas_t* getFTAtlas() const { return m_FTAtlas; }
			inline const ftgl::texture_font_t* getFTFont() const { return m_FTFont; }

			inline ftgl::texture_glyph_t* getGlyph(char c) const { return texture_font_get_glyph(m_FTFont, c); }

			inline const unsigned int getID() const { return m_FTAtlas->id; }
			inline const std::string& getName() const { return m_Name; }
			inline const unsigned int getSize() const { return m_FontSize; }
			inline const std::string& getFilename() const { return m_Filename; }
		private:
			ftgl::texture_atlas_t* m_FTAtlas;
			ftgl::texture_font_t* m_FTFont;

			std::string m_Name;
			std::string m_Filename;
			unsigned int m_FontSize;
		};
	}
}