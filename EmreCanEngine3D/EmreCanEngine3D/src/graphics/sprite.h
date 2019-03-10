#pragma once

#include "renderable2d.h"

namespace Can
{
	namespace Graphics
	{
		class Sprite : public Renderable2D
		{
		public:
			Sprite(Texture* texture);
			Sprite(float x, float y,  Texture* texture);
			Sprite(float x, float y, float width, float height, Texture* texture);
			Sprite(float x, float y, float width, float height, unsigned int color);
			Sprite(float x, float y, float width, float height, const maths::vec4& color);

			void SetUV(std::vector<maths::vec2> uv);
		public:
			maths::vec2& size;
		};
	}
}