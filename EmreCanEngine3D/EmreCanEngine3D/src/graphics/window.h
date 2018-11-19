#pragma once
namespace EmreCan3D
{
	namespace graphics
	{
		class Window
		{
		private:
			const char *name;
			int width, height;
		public:
			Window(const char *name, int width, int height);
			~Window();
			void update() const;
		};
	}
}