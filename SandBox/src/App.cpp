#include <REngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public REngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (REngine::Input::IsKeyPressed(REngine::KeyCodes::Key_A))
			RE_TRACE("A");
	}

	virtual void OnImGuiRender() override
	{
		
	}

	void OnEvent(REngine::Event& event) override
	{
		RE_TRACE("{0}", event);
	}
};

class Sandbox : public REngine::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};


REngine::Application* REngine::CreateApplication(){
	return new Sandbox();
}