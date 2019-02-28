﻿#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "maths.h"
namespace EmreCan3D
{
	namespace maths
	{
		struct mat4
		{
			union
			{
				float elements[4 * 4];
				vec4 columns[4];
			};
			mat4();
			mat4(float diagoal);

			vec4 getColumn(int index)
			{
				index *= 4;
				return vec4(elements[index + 0], elements[index + 1], elements[index + 2], elements[index + 3]);
			}

			static mat4 identity();

			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			vec3 multiply(const vec3& other) const;
			friend vec3 operator*(const mat4& left, const vec3& right);

			vec4 multiply(const vec4& other) const;
			friend vec4 operator*(const mat4& left, const vec4& right);

			mat4& invert();

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fow, float aspectRatio, float near, float far);

			static mat4 translate(const vec3& translation);
			static mat4 rotate(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);
		};
	}
}