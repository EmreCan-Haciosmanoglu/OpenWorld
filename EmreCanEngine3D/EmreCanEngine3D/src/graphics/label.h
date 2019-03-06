#pragma once
#include "renderable2d.h"
#include "font_manager.h"
namespace Can
{
	namespace graphics
	{
		class Label :public Renderable2D
		{
		public:
			Label();
			Label(const std::string& text, float x, float y, unsigned int color);
			Label(const std::string& text, float x, float y, Font* font, unsigned int color);
			Label(const std::string& text, float x, float y, const std::string& font, unsigned int color);
			Label(const std::string& text, float x, float y, const std::string& font, unsigned int size, unsigned int color);

			void submit(Renderer2D* renderer) const override;
		private:
			Font* m_Font;
			std::string m_Text;
		private:
			void validateFont(const std::string& name, unsigned int size = -1) ;
		};
	}
}