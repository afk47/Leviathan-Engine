	#include <Leviathan.h>

	#include "imgui.h"

	class ExampleLayer : public Leviathan::Layer
	{
	public:
	ExampleLayer()
		: Layer("Example")
	{
		m_Mesh.reset(Leviathan::Mesh::Create());

		float vertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		std::shared_ptr<Leviathan::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Leviathan::VertexBuffer::Create(vertices, sizeof(vertices)));
		Leviathan::BufferLayout layout = {
			{ Leviathan::ShaderDataType::Vec3, "a_Position" },
			{ Leviathan::ShaderDataType::Vec2, "a_TexCoord" }
		};
		vertexBuffer->SetLayout(layout);
		m_Mesh->AddVertexBuffer(vertexBuffer);
		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Leviathan::IndexBuffer> squareIB;
		squareIB.reset(Leviathan::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_Mesh->SetIndexBuffer(squareIB);

		m_Shader.reset(Leviathan::Shader::Create("assets/shaders/Textureshader.glsl"));

		m_Texture = std::make_shared<Leviathan::Texture>("assets/textures/transparencytest.png");
		
		m_Camera = new Leviathan::PerspectiveCamera(90.0f, 16 / 9, .001f, 9999.9f);
		m_Scene->SetCamera(m_Camera);
		entity = m_Scene->CreateEntity();
		{
			Leviathan::MeshComponent mesh = Leviathan::MeshComponent();
			mesh.mesh = m_Mesh;
			mesh.material->SetShader(m_Shader);
			mesh.material->Bind();
			mesh.material->Set("u_Texture", 0);
			mesh.material->SetTexture(m_Texture);
			entity.AddComponent<Leviathan::MeshComponent>(mesh);
		}
		entity.GetComponent<Leviathan::TransformComponent>().Rotation = m_Rotation;
		
		
		}

	void OnUpdate(Leviathan::Timestep ts) override
	{
		m_Camera->SetPosition(cam_Position);
		m_Camera->SetRotation(cam_Rotation);
		entity.GetComponent<Leviathan::TransformComponent>().Rotation = m_Rotation;
		entity.GetComponent<Leviathan::TransformComponent>().Translation = m_Position;
		entity.GetComponent<Leviathan::TransformComponent>().Scale = m_Scale;
		m_Scene->OnUpdate(ts);
	}

	virtual void OnImGuiRender(Leviathan::Timestep ts) override
	{
		ImGui::Begin("Settings");
		ImGui::SliderFloat3("Rotation", glm::value_ptr(m_Rotation), 0.1f, 6.28f);
		ImGui::SliderFloat3("Position", glm::value_ptr(m_Position), -5.0f, 5.0f);
		ImGui::SliderFloat3("Scale", glm::value_ptr(m_Scale), 0.1f, 5.0f);

		ImGui::Begin("Camera");
		ImGui::SliderFloat3("Position", glm::value_ptr(cam_Position), -9.0f, 9.0f);
		ImGui::SliderFloat3("Rotation", glm::value_ptr(cam_Rotation), 0.1f, 9.0f);
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
	Leviathan::Entity entity;
	Leviathan::Entity cameraentity;

	std::shared_ptr<Leviathan::Shader> m_Shader;
	std::shared_ptr<Leviathan::Mesh> m_Mesh;
	std::shared_ptr<Leviathan::Texture> m_Texture;

	glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_Scale = { 1.0f, 1.0f, 1.0f };
	};



	class Sandbox : public Leviathan::Application {

	public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
	};


	Leviathan::Application* Leviathan::CreateApplication(){
	return new Sandbox();
	}