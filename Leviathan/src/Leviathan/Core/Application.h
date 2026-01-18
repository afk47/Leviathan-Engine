#pragma once

#include "Core.h"

#include "Window.h"
#include "Leviathan/Core/LayerStack.h"
#include "Leviathan/Events/Event.h"
#include "Leviathan/Events/ApplicationEvent.h"

#include "Leviathan/ImGui/ImGuiLayer.h"

#include "Leviathan/Renderer/Shader.h"
#include "Leviathan/Renderer/Buffer.h"
#include "Leviathan/Renderer/Mesh.h"
#include "Leviathan/Renderer/Renderer.h"


namespace Leviathan {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		Unique<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		Unique<RendererAPI> m_RenderAPI;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}