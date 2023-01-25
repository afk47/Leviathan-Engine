#pragma once

#include "Core.h"

#include "Window.h"
#include "REngine/Core/LayerStack.h"
#include "REngine/Events/Event.h"
#include "REngine/Events/ApplicationEvent.h"

#include "REngine/ImGui/ImGuiLayer.h"

#include "REngine/Renderer/Shader.h"
#include "REngine/Renderer/Buffer.h"
#include "REngine/Renderer/VertexArray.h"

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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}