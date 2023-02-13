#include "repch.h"
#include "Renderer.h"

namespace REngine {

	
	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const Ref<Material>& material, const Ref<Mesh>& mesh)
	{
		material->Bind();
		mesh->Bind();
		RenderTask::DrawIndexed(mesh);
	}
}