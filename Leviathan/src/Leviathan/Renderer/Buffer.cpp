#include "lpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Leviathan/Platform/OpenGL/OpenGLBuffer.h"

namespace Leviathan {


	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: LE_CORE_ASSERT(false, "No Renderer API") return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}
		LE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: LE_CORE_ASSERT(false, "No Renderer API") return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}
		LE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}