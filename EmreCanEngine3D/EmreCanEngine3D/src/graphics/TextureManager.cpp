#include "TextureManager.h"

namespace Can
{
	namespace Graphics
	{
		std::vector<Texture*> TextureManager::m_Textures;
		void TextureManager::add(Texture * texture)
		{
			m_Textures.push_back(texture);
		}
		Texture * TextureManager::get()
		{
			return m_Textures[0];
		}
		Texture * TextureManager::get(const std::string & name)
		{
			for (Texture* tex : m_Textures)
				if (tex->getName() == name)
					return tex;
			return nullptr;
		}
		void TextureManager::clean()
		{
			for (int i = 0; i < m_Textures.size(); i++)
				delete m_Textures[i];
		}
	}
}