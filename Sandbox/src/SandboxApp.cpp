
#include "OneGameEngine.h"


class Sandbox : public OneGameEngine::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

OneGameEngine::Application* OneGameEngine::CreateApplication()
{
	return new Sandbox();
}