#include "group.h"

namespace EmreCan3D
{
	namespace graphics
	{
		Group::Group(const maths::mat4& transform)
			:m_TransformationStack(transform)
		{
		}
		void Group::add(Renderable2D * renderable)
		{
			m_Renderables.push_back(renderable);
		}
		void Group::submit(Renderer2D * renderer) const
		{
			renderer->push(m_TransformationStack);
			for (const Renderable2D* renderable : m_Renderables)
				renderable->submit(renderer);
			renderer->pop();
		}
	}
}