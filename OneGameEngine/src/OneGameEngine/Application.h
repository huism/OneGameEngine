#pragma once

#include "Core.h"

namespace OneGameEngine {
	class OGE_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

