#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../utils/fileutils.h"

namespace EmreCan3D
{
	namespace graphics
	{
		class Shader
		{
		private:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath; //For Debug
		public:
			Shader(const char * vertPath, const char *fragPath);
			~Shader();

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
	}
}