#pragma once

#include <GL/glew.h>
#include "../utils/fileutils.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Shader
		{
		private:
			GLuint shader;
		public:
			Shader(const char * vertPath, const char *fragPath);
			~Shader();

			void enable() const;
			void disable() const;
		};
	}
}