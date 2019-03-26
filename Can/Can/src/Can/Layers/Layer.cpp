#include "Layer.h"

namespace Can::Layer
{
	Layer::Layer(const std::string& name)
		:m_DebugName(name), m_Enabled(true)
	{
	}

	Layer::~Layer()
	{
	}
}