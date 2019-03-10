#pragma once
#include <string>
#include <vector>
#include "texture.h"

namespace Can
{
	namespace Graphics
	{
		class TextureManager
		{
		public:
			static void add(Texture* texture);
			static Texture* get();
			static Texture* get(const std::string& name);
			static void clean();
		private:
			TextureManager() {}
		private:
			static std::vector<Texture*> m_Textures;
		};
	}
}