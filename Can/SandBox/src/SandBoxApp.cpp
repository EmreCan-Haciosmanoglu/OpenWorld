#include <Can.h>

class SandBox : public Can::Application
{
public:
	SandBox()
	{
		
	}
	~SandBox()
	{

	}

private:

};

Can::Application* Can::CreateApplication()
{
	return new SandBox();
}