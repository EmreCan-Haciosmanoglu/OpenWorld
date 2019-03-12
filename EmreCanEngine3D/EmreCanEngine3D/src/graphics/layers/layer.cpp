#include "layer.h"

namespace Can
{
	namespace Graphics
	{
		Layer::Layer(Renderer2D * renderer, Shader * shader, maths::mat4 projectionMatrix)
			:m_Renderer(renderer)
			,m_Shader(shader)
			,m_ProjectionMatrix(projectionMatrix)
		{
			m_Shader->enable();
			m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);

			GLint texIDs[] =
			{
				 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
				10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
				20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
				30
			};
			m_Shader->setUniform1iv("textures", texIDs, 31);
			m_Shader->setUniform1i("mask_texture", 31);

			m_Shader->disable();
		}
		Layer::~Layer()
		{
			delete m_Shader;
			delete m_Renderer;

			for (uint i = 0; i < m_Renderables.size(); i++)
				delete m_Renderables[i];
		}
		Renderable2D* Layer::add(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
			return renderable;
		}
		void Layer::render()
		{
			m_Shader->enable();
			m_Renderer->begin();

			for (const Renderable2D* renderable : m_Renderables)
				renderable->submit(m_Renderer);

			//m_Renderer->drawString("Hello!", maths::vec3(0, 0, 0),80,0xffffffff);

			m_Renderer->end();
			m_Renderer->flush();
			// m_Shader->disable();
		}
	}
}