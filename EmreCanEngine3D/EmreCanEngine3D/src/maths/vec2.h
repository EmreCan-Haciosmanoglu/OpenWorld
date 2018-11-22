#pragma once

namespace EmreCan3D
{
	namespace maths
	{
		struct vec2 {
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& devide(const vec2& other);
		};
	}
}
