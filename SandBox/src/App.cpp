	#include <REngine.h>

	#include "imgui/imgui.h"

	class ExampleLayer : public REngine::Layer
	{
	public:
	ExampleLayer()
		: Layer("Example")
	{
		m_Mesh.reset(REngine::Mesh::Create());

		float vertices[3 * 8] = {
		 -1, -1,  0.5, //0
		 1, -1,  0.5, //1
		-1,  1,  0.5, //2
		 1,  1,  0.5, //3
		-1, -1, -0.5, //4
		 1, -1, -0.5, //5
		-1,  1, -0.5, //6
		 1,  1, -0.5  //7
		};

		std::shared_ptr<REngine::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(REngine::VertexBuffer::Create(vertices, sizeof(vertices)));
		REngine::BufferLayout layout = {
			{ REngine::ShaderDataType::Vec3, "a_Position" }
		};
		vertexBuffer->SetLayout(layout);
		m_Mesh->AddVertexBuffer(vertexBuffer);
		// 3(triangle) * faces * tris per face
		uint32_t squareIndices[3 * 6 * 2] = {   
			//Top
		2, 6, 7,
		2, 3, 7,

		//Bottom
		0, 4, 5,
		0, 1, 5,

		//Left
		0, 2, 6,
		0, 4, 6,

		//Right
		1, 3, 7,
		1, 5, 7,

		//Front
		0, 2, 3,
		0, 1, 3,

		//Back
		4, 6, 7,
		4, 5, 7 };
		std::shared_ptr<REngine::IndexBuffer> squareIB;
		squareIB.reset(REngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_Mesh->SetIndexBuffer(squareIB);

		//Create shaders
		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			uniform mat4 transformMatrix;
			uniform mat4 projectionMatrix;
			out mat4 transform;
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				transform = transformMatrix;
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = projectionMatrix * transformMatrix * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in mat4 transform;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = v_Color;
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

		m_Shader.reset(new REngine::Shader(vertexSrc, fragmentSrc));
		m_Camera = new REngine::PerspectiveCamera(90.0f, 16 / 9, .001f, 9999.9f);
		m_Scene->SetCamera(*m_Camera);
		entity = m_Scene->CreateEntity();
		{
			REngine::MeshComponent mesh = REngine::MeshComponent();
			mesh.mesh = m_Mesh;
			mesh.material->SetShader(m_Shader);
			entity.AddComponent<REngine::MeshComponent>(mesh);
		}
		entity.GetComponent<REngine::TransformComponent>().Rotation = m_Rotation;
		}

	void OnUpdate() override
	{
		entity.GetComponent<REngine::TransformComponent>().Rotation = m_Rotation;
		entity.GetComponent<REngine::TransformComponent>().Translation = m_Position;
		entity.GetComponent<REngine::TransformComponent>().Scale = m_Scale;
		m_Scene->OnUpdate();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::SliderFloat3("Rotation", glm::value_ptr(m_Rotation), 0.1f, 6.28f);
		ImGui::SliderFloat3("Position", glm::value_ptr(m_Position), -5.0f, 5.0f);
		ImGui::SliderFloat3("Scale", glm::value_ptr(m_Scale), 0.1f, 5.0f);
		ImGui::End();
	}

	void OnEvent(REngine::Event& event) override
	{
		RE_TRACE("{0}", event);
	}
	private:
	REngine::PerspectiveCamera* m_Camera;
	REngine::Entity entity;
	std::shared_ptr<REngine::Shader> m_Shader;
	std::shared_ptr<REngine::Mesh> m_Mesh;
	REngine::Scene* m_Scene = new REngine::Scene();
	glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_Scale = { 1.0f, 1.0f, 1.0f };
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