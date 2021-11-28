#pragma once

#ifdef OGE_PLATFORM_WINDOWS

extern OneGameEngine::Application* OneGameEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = OneGameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif