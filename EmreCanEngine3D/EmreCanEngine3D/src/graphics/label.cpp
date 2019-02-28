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
			m_Color = maths::vec4(0, 0, 0, 1);
			m_FontSize = 20; //TODO: Find better one
		}
		Label::Label(const std::string & text, float x, float y, unsigned int fontSize, const maths::vec4 & color)
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