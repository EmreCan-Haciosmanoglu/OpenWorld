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
			Label(const std::string& text, float x, float y, Font* font, unsigned int color);

			void submit(Renderer2D* renderer) const override;
		private:
			Font* m_Font;
			std::string m_Text;
		};
	}
}