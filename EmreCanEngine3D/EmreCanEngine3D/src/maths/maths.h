#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace Can
{
	namespace maths
	{
		inline float toRadians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}

		inline float toDegrees(float radians)
		{
			return radians * (180.0f / M_PI);
		}

		inline int sign(float value)
		{
			return (value > 0) - (value < 0);
		}

	}
}