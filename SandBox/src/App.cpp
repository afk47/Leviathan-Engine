#include <REngine.h>

class ExampleLayer : public REngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		RE_INFO("ExampleLayer::Update");
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
		PushOverlay(new REngine::ImGuiLayer());
	}
	~Sandbox() {

	}
};


REngine::Application* REngine::CreateApplication(){
	return new Sandbox();
}