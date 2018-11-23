#include "mat4.h"
#define LENGTH 4*4
namespace EmreCan3D
{
	namespace maths
	{
		mat4::mat4()
		{
			for (int i = 0; i < LENGTH; i++)
			{
				elements[i] = 0.0f;
			}
		}

		mat4::mat4(float diagoal)
		{
			for (int i = 0; i < LENGTH; i++)
			{
				elements[i] = 0.0f;
			}

			elements[0 + 0 * 4] = diagoal;
			elements[1 + 1 * 4] = diagoal;
			elements[2 + 2 * 4] = diagoal;
			elements[3 + 3 * 4] = diagoal;
		}

		mat4  mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4 &  mat4::multiply(const mat4 & other)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
				}
			}
		}

		mat4  operator*(mat4 left, const mat4 & right)
		{
			return left.multiply(right);
		}

		mat4 &  mat4::operator*=(const mat4 & other)
		{
			return multiply(other);
		}

		mat4  mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4  mat4::perspective(float fow, float aspectRatio, float near, float far)
		{
			mat4 result(1.0f);

			return result;
		}

		mat4  mat4::translation(const vec3 & translation)
		{
			return mat4();
		}

		mat4  mat4::ratation(float angle, const vec3 & axis)
		{
			return mat4();
		}

		mat4  mat4::scale(const vec3 & scale)
		{
			return mat4();
		}
	}
}