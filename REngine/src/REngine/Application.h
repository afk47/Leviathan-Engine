#pragma once
#include "Core.h"

namespace RE{

	class RENGINE_API Application
	{
	public:
		Application();
		~Application();
		void Run();
	};
	
	//Defined in client
	Application* CreateApplication();
	
}

