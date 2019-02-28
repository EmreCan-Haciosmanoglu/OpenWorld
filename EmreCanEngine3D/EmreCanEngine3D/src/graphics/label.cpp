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
			m_FontSize = 20; //TODO: Find better one
		}
		Label::Label(const std::string & text, float x, float y, unsigned int fontSize, unsigned int color)
			: Renderable2D()
			, m_Text(text)
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_FontSize = fontSize;
			m_Color = color;
		}
		void Label::submit(Renderer2D * renderer) const
		{
			renderer->drawString(m_Text, m_Position, m_FontSize, m_Color);
		}
	}
}