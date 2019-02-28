#pragma once

#include "renderable2d.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Sprite : public Renderable2D
		{
		public:
			Sprite(float x, float y, float width, float height, unsigned int color);
			Sprite(float x, float y, float width, float height, Texture* texture);

		private:

		};
	}
}