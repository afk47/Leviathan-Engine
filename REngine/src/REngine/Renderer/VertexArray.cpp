#include "repch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "REngine/Platform/OpenGL/OpenGLVertexArray.h"

namespace REngine {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: RE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}
		RE_CORE_ASSERT(false, "RENDERAPI NOT SUPPORTED"); 
		return nullptr;
	}

}