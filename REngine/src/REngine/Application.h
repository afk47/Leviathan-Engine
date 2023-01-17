#pragma once
#include "Core.h"

namespace REngine {

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

