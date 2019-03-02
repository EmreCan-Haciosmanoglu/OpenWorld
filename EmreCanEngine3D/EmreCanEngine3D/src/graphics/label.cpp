#include "label.h"

namespace EmreCan3D
{
	namespace graphics
	{
		Label::Label()
			: Renderable2D()
			, m_Text("")
		{
			m_Position = maths::vec3(0, 0, 0);
			m_Color = 0x000000ff;
		}
		Label::Label(const std::string & text, float x, float y, unsigned int color)
			: Renderable2D()
			, m_Font(FontManager::get("Arial", 32))
			, m_Text(text)
		{}
		Label::Label(const std::string & text, float x, float y, Font* font, unsigned int color)
			: Renderable2D()
			, m_Font(font)
			, m_Text(text)
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_Color = color;
		}
		Label::Label(const std::string & text, float x, float y, const std::string & font, unsigned int color)
			: Renderable2D()
			, m_Font(FontManager::get(font))
			, m_Text(text)
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_Color = color;

			validateFont(font);
		}
		Label::Label(const std::string & text, float x, float y, const std::string & font, unsigned int size, unsigned int color)
			: Renderable2D()
			, m_Font(FontManager::get(font, size))
			, m_Text(text)
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_Color = color;

			validateFont(font, size);
		}
		void Label::submit(Renderer2D * renderer) const
		{
			renderer->drawString(m_Text, m_Position, *m_Font, m_Color);
		}
		void Label::validateFont(const std::string& name, unsigned int size)
		{
			if (m_Font != nullptr)
				return;

			std::cout << "NULL FONT! font= " << name;
			if (size > 0)
				std::cout << ", size= " << size;
			std::cout << std::endl;

			m_Font = FontManager::get("Arial", 32);
		}
	}
}