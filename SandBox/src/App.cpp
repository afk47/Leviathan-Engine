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

	

		entity = m_Scene->LoadMeshes("assets/models/teapot.obj", m_Shader);
		
		entity.insert(entity.begin(), m_Scene->CreateEntity("MeshTest"));

		//		//TEST QUAD USING MANUAL MESH DEFINITION
		//		MeshComponent comp = MeshComponent();
		//
		//		float vertices[3 * 4] = {
		//			-0.5f, -0.5f, 0.0f,
		//			 0.5f, -0.5f, 0.0f,
		//			 0.5f,  0.5f, 0.0f,
		//			-0.5f,  0.5f, 0.0f,
		//		};
		//		std::shared_ptr<VertexBuffer> vertexBuffer;
		//		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		//		BufferLayout layout = {
		//			{ ShaderDataType::Vec3, "a_Position" }
		//		};
		//		vertexBuffer->SetLayout(layout);
		//		comp.mesh->AddVertexBuffer(vertexBuffer);
		//		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		//		std::shared_ptr<IndexBuffer> squareIB;
		//		squareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		//		comp.mesh->SetIndexBuffer(squareIB);
		//		comp.material->SetShader(m_Shader2);
		//		comp.material->Bind();
		//
		//		entity.at(0).AddComponent<MeshComponent>(comp);
		
		
	}

	void OnUpdate(Leviathan::Timestep ts) override
	{
		m_Camera->SetPosition(cam_Position);
		m_Camera->SetRotation(cam_Rotation);
		
		
		entity.at(0).GetComponent<Leviathan::TransformComponent>().Rotation = m_Rotation;
		entity.at(0).GetComponent<Leviathan::TransformComponent>().Translation = m_Position;
		entity.at(0).GetComponent<Leviathan::TransformComponent>().Scale = m_Scale;
		m_Scene->OnUpdate(ts);
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

	void OnEvent(Leviathan::Event& event) override
	{
		
	}
	private:
	Leviathan::PerspectiveCamera* m_Camera;
	glm::vec3 cam_Position = { 0.0f, 0.0f, 0.0f };
	glm::vec3 cam_Rotation = { 0.0f, 0.0f, 0.0f };

	Leviathan::Scene* m_Scene = new Leviathan::Scene();
	std::vector<Leviathan::Entity> entity;
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