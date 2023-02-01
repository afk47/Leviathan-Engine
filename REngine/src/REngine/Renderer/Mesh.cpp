#include "repch.h"
#include "Mesh.h"

#include "Renderer.h"
#include "REngine/Platform/OpenGL/OpenGLMesh.h"

namespace REngine {

	Mesh* Mesh::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: RE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLMesh();
		}
		RE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); 
		return nullptr;
	}

}