#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "maths.h"
namespace EmreCan3D
{
	namespace maths
	{
		struct mat4
		{
			float elements[4 * 4];
			mat4();
			mat4(float diagoal);

			static mat4 identity();

			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fow, float aspectRatio,float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 ratation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);
		};
	}
}