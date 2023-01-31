#include "repch.h"
#include "Renderer.h"

#include <glad/glad.h>
namespace REngine {

	

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         RE_CORE_ERROR(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       RE_CORE_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          RE_CORE_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: RE_CORE_TRACE(message); return;
		}

		RE_CORE_ASSERT(false, "Unknown severity level!");
	}

	void Renderer::Init()
	{
#ifdef RE_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);
	}

	void Renderer::Shutdown()
	{

	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		glViewport(0, 0, width, height);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Render(std::shared_ptr<Shader> shader, std::shared_ptr<Mesh> mesh)
	{
		
		shader->Bind();
// 		shader->SetMat4("u_ViewProjection", Scene.getViewProjection());
		shader->SetMat4("u_Transform", m_Camera.GetViewProjectionMatrix());
 		mesh->Bind();
		uint32_t count = mesh->GetIndexBuffer()->GetCount();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}

	RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;



}