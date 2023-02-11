#include <REngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public REngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		m_Mesh.reset(REngine::Mesh::Create());

		float vertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<REngine::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(REngine::VertexBuffer::Create(vertices, sizeof(vertices)));
		REngine::BufferLayout layout = {
			{ REngine::ShaderDataType::Vec3, "a_Position" }
		};
		vertexBuffer->SetLayout(layout);
		m_Mesh->AddVertexBuffer(vertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<REngine::IndexBuffer> squareIB;
		squareIB.reset(REngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_Mesh->SetIndexBuffer(squareIB);

		//Create shaders
		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new REngine::Shader(vertexSrc, fragmentSrc));
		
		REngine::Entity entity = m_Scene->CreateEntity();
		{
			REngine::MeshComponent mesh = REngine::MeshComponent();
			mesh.mesh = m_Mesh;
			mesh.shader = m_Shader;
			entity.AddComponent<REngine::MeshComponent>(mesh);
		}
		}

	void OnUpdate() override
	{
		m_Scene->OnUpdate();
	}

	virtual void OnImGuiRender() override
	{
		
	}

	void OnEvent(REngine::Event& event) override
	{
		RE_TRACE("{0}", event);
	}
private:
	std::shared_ptr<REngine::Shader> m_Shader;
	std::shared_ptr<REngine::Mesh> m_Mesh;
	REngine::Scene* m_Scene = new REngine::Scene();
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
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