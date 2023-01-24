#include "repch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "REngine/Platform/OpenGL/OpenGLBuffer.h"

namespace REngine {


	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: RE_CORE_ASSERT(false, "No Renderer API") return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: RE_CORE_ASSERT(false, "No Renderer API") return nullptr;
		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}
	}

}