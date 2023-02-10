#pragma once

#include "Core.h"

#include "Window.h"
#include "REngine/Core/LayerStack.h"
#include "REngine/Events/Event.h"
#include "REngine/Events/ApplicationEvent.h"

#include "REngine/ImGui/ImGuiLayer.h"

#include "REngine/Renderer/Shader.h"
#include "REngine/Renderer/Buffer.h"
#include "REngine/Renderer/Mesh.h"
#include "REngine/Renderer/Renderer.h"

namespace REngine {

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