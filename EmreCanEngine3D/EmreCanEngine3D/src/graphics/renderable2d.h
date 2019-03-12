#pragma once
#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"

#include "renderer2d.h"
#include "texture.h"

#include "../maths/maths.h"
#include "shader.h"

namespace Can
{
	namespace Graphics
	{
		struct VertexData
		{
			maths::vec3 vertex;
			maths::vec2 uv;
			float tid;
			unsigned int color;
		};
		class Renderable2D
		{
		protected:
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			unsigned int m_Color;
			std::vector<maths::vec2> m_UV;
			Texture* m_Texture;
		protected:
			Renderable2D() :m_Texture(nullptr)
			{
				setUVDefaults();
			}
		public:
			Renderable2D(maths::vec3 pos, maths::vec2 size, unsigned int color)
				:m_Position(pos)
				, m_Size(size)
				, m_Color(color)
				, m_Texture(nullptr)
			{
				setUVDefaults();
			}

			virtual ~Renderable2D(){}

			virtual void submit(Renderer2D* renderer) const
			{
				renderer->submit(this);
			}

			virtual void setPosition(maths::vec3 pos)
			{
				m_Position = pos;
			}

			void setColor(unsigned int color) { m_Color = color; }
			void setColor(const maths::vec4& color)
			{
				int r = (int)(color.x * 255.0f);
				int g = (int)(color.y * 255.0f);
				int b = (int)(color.z * 255.0f);
				int a = (int)(color.w * 255.0f);

				m_Color = a << 24 | b << 16 | g << 8 | r;
			}

			inline const maths::vec3& getPosition() const { return m_Position; }
			inline const maths::vec2& getSize() const { return m_Size; }
			inline const unsigned int getColor() const { return m_Color; }
			inline const std::vector<maths::vec2>& getUV() const { return m_UV; }

			inline const GLuint getTID() const { return m_Texture ? m_Texture->getID() : 0; }
		private:
			void setUVDefaults()
			{
				m_UV.push_back(maths::vec2(0, 0));
				m_UV.push_back(maths::vec2(0, 1));
				m_UV.push_back(maths::vec2(1, 1));
				m_UV.push_back(maths::vec2(1, 0));
			}
		};
	}
}