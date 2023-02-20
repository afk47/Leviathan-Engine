#include "lpch.h"
#include "Application.h"

#include "Leviathan/Core/Log.h"
#include "Leviathan/Utils/Timer.h"

#include "glad/glad.h"

namespace Leviathan {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;



	Application::Application()
	{
		LE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Unique<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
		m_RenderAPI = RendererAPI::Create();
		m_RenderAPI->Init();
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		Timestep ts = Timestep();
		while (m_Running)
		{
			Timer timer = Timer();
			LE_PROFILE_SCOPE("Main Loop");
			

			m_RenderAPI->SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			m_RenderAPI->Clear();

			{
				LE_PROFILE_SCOPE("Layers");
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(ts);
			}
			
			{
				LE_PROFILE_SCOPE("ImGUI");
				m_ImGuiLayer->Begin();

				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender(ts);

				m_ImGuiLayer->End();
			}
			m_Window->OnUpdate();
			ts = Timestep(timer.GetElapsed());
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	

}