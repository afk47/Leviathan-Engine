#include "lpch.h"
#include "Mesh.h"

#include "Renderer.h"
#include "Leviathan/Platform/OpenGL/OpenGLVertexArray.h"

namespace Leviathan {

	Mesh* Mesh::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		}
		LE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); 
		return nullptr;
	}

}