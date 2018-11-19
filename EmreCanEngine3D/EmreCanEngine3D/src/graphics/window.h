#pragma once
namespace EmreCan3D
{
	namespace graphics
	{
		class Window
		{
		private:
			const char *m_Name;
			int m_Width, m_Height;
		public:
			Window(const char *name, int width, int height);
			~Window();
			void update() const;
		};
	}
}