#include "repch.h"
#include "Mesh.h"

#include "Renderer.h"
#include "REngine/Platform/OpenGL/OpenGLVertexArray.h"

namespace REngine {

	Mesh* Mesh::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: RE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		}
		RE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); 
		return nullptr;
	}

}