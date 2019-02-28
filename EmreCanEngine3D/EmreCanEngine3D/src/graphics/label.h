#pragma once
#include "renderable2d.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Label :public Renderable2D
		{
		public:
			Label();
			Label(const std::string& text, float x, float y, unsigned int fontSize, const maths::vec4& color);

			void submit(Renderer2D* renderer) const override;
		private:
			std::string m_Text;
			unsigned int m_FontSize;
		};
	}
}