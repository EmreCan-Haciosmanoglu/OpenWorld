#include "static_sprite.h"

namespace EmreCan3D
{
	namespace graphics
	{
		StaticSprite::StaticSprite(float x, float y, float width, float height, unsigned int color, Shader& shader)
			: Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color), m_Shader(shader)
		{
			m_VertexArray = new VertexArray();
			GLfloat vertices[] =
			{
				0,0,0,
				0, height,0,
				width,height,0,
				width,0,0
			};
			maths::vec4 co(1, 0, 1, 1);
			GLfloat colors[] =
			{
				co.x,co.y,co.z,co.w,
				co.x,co.y,co.z,co.w,
				co.x,co.y,co.z,co.w,
				co.x,co.y,co.z,co.w
			};

			m_VertexArray->addBuffers(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffers(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0,1,2,2,3,0 };
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}
		StaticSprite::~StaticSprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}
