#pragma once
#include "Core.h"
#include "REngine/Events/Event.h"
#include "REngine/Events/ApplicationEvent.h"
#include "Window.h"

namespace REngine {

	class RENGINE_API Application
	{
	public:
		Application();
		~Application();
		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	//Defined in client
	Application* CreateApplication();
	
}

