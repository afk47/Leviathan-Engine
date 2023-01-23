#include "repch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "REngine/Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "REngine/Core/Application.h"

#include "REngine/Core/Input/KeyCodes.h"

#include <glad/glad.h>

namespace REngine {


	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;


		// TEMPORARY: should eventually use Hazel key codes
		io.KeyMap[ImGuiKey_Tab] = Tab;
		io.KeyMap[ImGuiKey_LeftArrow] = Left;
		io.KeyMap[ImGuiKey_RightArrow] = Right;
		io.KeyMap[ImGuiKey_UpArrow] = Up;
		io.KeyMap[ImGuiKey_DownArrow] = Down;
		io.KeyMap[ImGuiKey_PageUp] = PageUp;
		io.KeyMap[ImGuiKey_PageDown] = PageDown;
		io.KeyMap[ImGuiKey_Home] = Home;
		io.KeyMap[ImGuiKey_End] = End;
		io.KeyMap[ImGuiKey_Insert] = Insert;
		io.KeyMap[ImGuiKey_Delete] = Delete;
		io.KeyMap[ImGuiKey_Backspace] = Backspace;
		io.KeyMap[ImGuiKey_Space] = Space;
		io.KeyMap[ImGuiKey_Enter] = Enter;
		io.KeyMap[ImGuiKey_Escape] = Escape;
		io.KeyMap[ImGuiKey_A] = A;
		io.KeyMap[ImGuiKey_C] = C;
		io.KeyMap[ImGuiKey_V] = V;
		io.KeyMap[ImGuiKey_X] = X;
		io.KeyMap[ImGuiKey_Y] = Y;
		io.KeyMap[ImGuiKey_Z] = Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());
		
		
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	
	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(RE_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[LeftControl] || io.KeysDown[RightControl];
		io.KeyShift = io.KeysDown[LeftShift] || io.KeysDown[RightShift];
		io.KeyAlt = io.KeysDown[LeftAlt] || io.KeysDown[RightAlt];
		io.KeySuper = io.KeysDown[LeftSuper] || io.KeysDown[RightSuper];

		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		io.KeyCtrl = io.KeysDown[LeftControl] || io.KeysDown[RightControl];
		io.KeyShift = io.KeysDown[LeftShift] || io.KeysDown[RightShift];
		io.KeyAlt = io.KeysDown[LeftAlt] || io.KeysDown[RightAlt];
		io.KeySuper = io.KeysDown[LeftSuper] || io.KeysDown[RightSuper];

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);
		
		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		glClearColor(0.4f, .7f, .7f, 1);
		return false;
	}

}