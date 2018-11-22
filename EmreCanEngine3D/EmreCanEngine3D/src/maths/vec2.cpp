#include "vec2.h"


namespace EmreCan3D
{
	namespace maths
	{
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}
		vec2::vec2(const float & x, const float & y)
		{
			this->x = x;
			this->y = y;
		}
		vec2 & vec2::add(const vec2 & other)
		{
			x += other.x;
			y += other.y;
			return (*this);
		}
		vec2 & vec2::subtract(const vec2 & other)
		{
			x -= other.x;
			y -= other.y;
			return (*this);
		}
		vec2 & vec2::multiply(const vec2 & other)
		{
			x *= other.x;
			y *= other.y;
			return (*this);
		}
		vec2 & vec2::devide(const vec2 & other)
		{
			x /= other.x;
			y /= other.y;
			return (*this);
		}
	}
}