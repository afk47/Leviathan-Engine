#pragma once
#include "Core.h"


#include "Window.h"
#include "REngine/LayerStack.h"
#include "REngine/Events/Event.h"
#include "REngine/Events/ApplicationEvent.h"


namespace REngine {

	class RENGINE_API Application
	{
	public:
		Application();
		~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	
	//Defined in client
	Application* CreateApplication();
	
}

