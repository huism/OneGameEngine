#pragma once

#ifdef OGE_PLATFORM_WINDOWS

extern OneGameEngine::Application* OneGameEngine::CreateApplication();

int main(int argc, char** argv)
{
	OneGameEngine::Log::Init();
	OGE_CORE_WARN("Initialized Log!");
	int a = 5;
	OGE_INFO("Hello! Var={0}", a);

	auto app = OneGameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif