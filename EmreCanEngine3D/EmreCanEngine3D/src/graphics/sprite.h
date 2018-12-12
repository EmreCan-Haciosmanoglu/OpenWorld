#pragma once

#include "renderable2d.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Sprite : public Renderable2D
		{
		public:
			Sprite(float x, float y, float width, float height, const maths::vec4& color);

		private:

		};
	}
}