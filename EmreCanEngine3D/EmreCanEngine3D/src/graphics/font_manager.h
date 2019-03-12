#pragma once
#include <vector>
#include "font.h"
#include <CustomTypes.h>

namespace Can
{
	namespace Graphics
	{
		class FontManager
		{
		public:
			static void add(Font* font);
			static Font* get();
			static Font* get(const std::string& name);
			static Font* get(const std::string& name, unsigned int size);
			static void clean();
		private:
			FontManager() {}
		public:
		private:
			static std::vector<Font*> m_Fonts;
		};
	}
}