#include "lpch.h"
#include "Renderer.h"

namespace Leviathan {

	
	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const Ref<Material>& material, const Ref<Mesh>& mesh)
	{
		LE_PROFILE_FUNCTION();
		material->Bind();
		mesh->Bind();
		RenderTask::DrawIndexed(mesh);
	}
}