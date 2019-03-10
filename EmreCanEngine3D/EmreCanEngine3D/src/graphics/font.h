#pragma once

#include <string>
#include "../maths/vec2.h"
#include "../../ext/freetype-gl/freetype-gl.h"

namespace Can
{
	namespace Graphics
	{
		class Font
		{
		public:
			Font(std::string name, std::string filename, unsigned int size);

			void setScale(float x, float y);

			inline const ftgl::texture_atlas_t* getFTAtlas() const { return m_FTAtlas; }
			inline const ftgl::texture_font_t* getFTFont() const { return m_FTFont; }

			inline ftgl::texture_glyph_t* getGlyph(char c) const { return texture_font_get_glyph(m_FTFont, c); }

			inline const unsigned int getID() const { return m_FTAtlas->id; }
			inline const maths::vec2& getScale() const { return m_Scale; }
			inline const std::string& getName() const { return m_Name; }
			inline const std::string& getFilename() const { return m_Filename; }
			inline const unsigned int getSize() const { return m_FontSize; }
		private:
			ftgl::texture_atlas_t* m_FTAtlas;
			ftgl::texture_font_t* m_FTFont;

			std::string m_Name;
			std::string m_Filename;
			unsigned int m_FontSize;
			maths::vec2 m_Scale;
		};
	}
}