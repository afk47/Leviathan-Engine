	#include <Leviathan.h>

#include "imgui.h"
	class ExampleLayer : public Leviathan::Layer
	{
	public:
	ExampleLayer()
		: Layer("Example")
	{
		using namespace Leviathan;

		LE_PROFILE_SCOPE("INIT LAYER");

		m_Shader.reset(Shader::Create("assets/shaders/solid.glsl"));

		m_Shader2.reset(Shader::Create("assets/shaders/solid2.glsl"));

		m_Camera = new PerspectiveCamera(90.0f, 16 / 9, .001f, 9999.9f);
		m_Scene->SetCamera(m_Camera);

	

		entity = m_Scene->LoadMesh("assets/models/teapot2.obj", m_Shader2);
		
	}

	void OnUpdate(Leviathan::Timestep ts) override
	{
		Leviathan::Input::LockMouse(cameraIsLocked);


		CameraControl(ts);

		auto[mX,mY] = Leviathan::Input::GetMousePos();
		
		cam_Rotation += glm::vec3({mouseY-mY, mouseX-mX, 0}) * .004f;
		mouseX = mX;
		mouseY = mY;

		m_Camera->SetPosition(cam_Position);
		m_Camera->SetRotation(cam_Rotation);
		
		
		entity.GetComponent<Leviathan::TransformComponent>().Rotation = m_Rotation;
		entity.GetComponent<Leviathan::TransformComponent>().Translation = m_Position;
		entity.GetComponent<Leviathan::TransformComponent>().Scale = m_Scale;
		m_Scene->OnUpdate(ts);
	}

	void CameraControl(Leviathan::Timestep ts)
	{

		glm::vec3 forward = glm::vec3(0);
		forward.x = cos(cam_Rotation.x) * sin(cam_Rotation.y);
		forward.y = -sin(cam_Rotation.x);
		forward.z = cos(cam_Rotation.x) * cos(cam_Rotation.y);

		glm::vec3 right = glm::vec3(0);
		right.x = cos(cam_Rotation.y);
		right.y = 0;
		right.z = -sin(cam_Rotation.y);

		float speed = .1;

		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_W))
		{
			cam_Position -= ts.GetMilliseconds() * (forward * speed);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_S))
		{
			cam_Position += ts.GetMilliseconds() * (forward * speed);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_D))
		{
			cam_Position += ts.GetMilliseconds() * (right * speed);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_A))
		{
			cam_Position -= ts.GetMilliseconds() * (right * speed);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_LeftControl))
		{
			cam_Position += ts.GetMilliseconds() * (glm::vec3({ 0, -1, 0 }) * speed);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_Space))
		{
			cam_Position += ts.GetMilliseconds() * (glm::vec3({ 0, 1, 0 }) * speed);
		}

		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_Left))
		{
			cam_Rotation += ts.GetMilliseconds() * (glm::vec3({ 0, 1, 0 }) * .004f);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_Right))
		{
			cam_Rotation += ts.GetMilliseconds() * (glm::vec3({ 0, -1, 0 }) * .004f);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_Up))
		{
			cam_Rotation += ts.GetMilliseconds() * (glm::vec3({ 1, 0, 0 }) * .004f);
		}
		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_Down))
		{
			cam_Rotation += ts.GetMilliseconds() * (glm::vec3({ -1, 0, 0 }) * .004f);
		}

		if (Leviathan::Input::IsKeyPressed(Leviathan::KeyCodes::Key_Escape))
		{
			cameraIsLocked = false;
		}

		if (Leviathan::Input::IsMouseButtonPressed(Leviathan::MouseCodes::MouseButton0))
		{
			cameraIsLocked = true;
		}
	}


	virtual void OnImGuiRender(Leviathan::Timestep ts) override
	{
		LE_PROFILE_SCOPE("LAYER GUI");
		ImGui::Begin("Settings");
		ImGui::SliderFloat3("Rotation", glm::value_ptr(m_Rotation), 0.0f, 6.28f);
		ImGui::SliderFloat3("Position", glm::value_ptr(m_Position), -5.0f, 5.0f);
		ImGui::SliderFloat3("Scale", glm::value_ptr(m_Scale), 0.1f, 5.0f);

		ImGui::Begin("Camera");
		ImGui::SliderFloat3("Position", glm::value_ptr(cam_Position), -20.0f, 20.0f);
		ImGui::SliderFloat3("Rotation", glm::value_ptr(cam_Rotation), 0.0f, 32.0f);
		ImGui::End();
		ImGui::End();
	}
	bool OnKeyPressed(Leviathan::KeyPressedEvent& e)
	{
		
		if (e.GetKeyCode() == Leviathan::KeyCodes::Key_A)
		{
			cam_Position += glm::vec3({ -.1, 0, 0 });
		}
		if (e.GetKeyCode() == Leviathan::KeyCodes::Key_D)
		{
			cam_Position += glm::vec3({ .1, 0, 0 });
		}
		if (e.GetKeyCode() == Leviathan::KeyCodes::Key_W)
		{
			cam_Position += glm::vec3({ 0, 0, -.1 });
		}
		if (e.GetKeyCode() == Leviathan::KeyCodes::Key_S)
		{
			cam_Position += glm::vec3({ 0, 0, .1 });
		}

		LE_CORE_INFO("KEY - {0}", e.GetKeyCode());
		return false;
	}

	void OnEvent(Leviathan::Event& event) override
	{
		

	}

	
	private:
	Leviathan::PerspectiveCamera* m_Camera;
	glm::vec3 cam_Position = { 0.0f, 0.0f, 0.0f };
	glm::vec3 cam_Rotation = { 0.0f, 0.0f, 0.0f };

	float mouseX = 0;
	float mouseY = 0;

	bool cameraIsLocked = true;

	Leviathan::Scene* m_Scene = new Leviathan::Scene();
	Leviathan::Entity entity;
	Leviathan::Entity cameraentity;

	std::shared_ptr<Leviathan::Shader> m_Shader;
	std::shared_ptr<Leviathan::Shader> m_Shader2;
	std::shared_ptr<Leviathan::Mesh> m_Mesh;
	std::shared_ptr<Leviathan::Texture> m_Texture;

	glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_Scale = { 1.0f, 1.0f, 1.0f };
	};



	class Sandbox : public Leviathan::Application {

	public:
	Sandbox() {
		LE_PROFILE_SCOPE("INIT APP");
	PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
	};


	Leviathan::Application* Leviathan::CreateApplication(){
	return new Sandbox();
	}