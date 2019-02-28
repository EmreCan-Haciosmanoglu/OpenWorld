#pragma once

#include "renderable2d.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class StaticSprite : public Renderable2D
		{
		public:
			StaticSprite(float x, float y, float width, float height, unsigned int color, Shader& shader);
			~StaticSprite();
			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }

			inline Shader& getShader() const { return m_Shader; }

		private:

			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;

			Shader& m_Shader;
		};
	}
}