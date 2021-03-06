#pragma once
#include <iostream>
namespace Can
{
	namespace maths
	{
		struct vec2;

		struct vec3 {
			float x, y, z;

			vec3();
			vec3(float x, float y, float z);
			vec3(const vec2& other);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& devide(const vec3& other);

			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other) const;
			bool operator!=(const vec3& other) const;

			float distance(const vec3& other) const;

			friend std::ostream& operator<<(std::ostream& stream, const vec3 vector);
		};
	}
}
