#include "repch.h"
#include "Renderer.h"

namespace REngine {

	
	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Mesh>& mesh)
	{
		shader->Bind();
		mesh->Bind();
		RenderTask::DrawIndexed(mesh);
	}
}