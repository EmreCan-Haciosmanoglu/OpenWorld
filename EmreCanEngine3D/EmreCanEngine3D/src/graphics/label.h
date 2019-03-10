#pragma once
#include "renderable2d.h"
#include "font_manager.h"
namespace Can
{
	namespace Graphics
	{
		class Label :public Renderable2D
		{
		public:
			Label();
			Label(const std::string& text, float x, float y, unsigned int color);
			Label(const std::string& text, float x, float y, Font* font, unsigned int color);
			Label(const std::string& text, float x, float y, const std::string& font, unsigned int color);
			Label(const std::string& text, float x, float y, const std::string& font, unsigned int size, unsigned int color);

			void setText(const std::string& text) { m_Text = text; }

			void submit(Renderer2D* renderer) const override;
			std::string m_Text;
		private:
			Font* m_Font;
		private:
			void validateFont(const std::string& name, unsigned int size = -1) ;
		};
	}
}