#pragma once

#include "../renderable2d.h"
#include "../renderer2d.h"
#include <CustomTypes.h>

namespace Can
{
	namespace Graphics
	{
		class Layer
		{
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;

			maths::mat4 m_ProjectionMatrix;
		public:
			Layer(Renderer2D* renderer,Shader* shader, maths::mat4 projectionMatrix);
			virtual ~Layer();
			virtual Renderable2D* add(Renderable2D* renderable);
			inline void setMask(const Texture* mask) const { m_Renderer->setMask(mask); }
			virtual void render();
		};
	}
}