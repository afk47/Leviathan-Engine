#include "lpch.h"
#include "RendererAPI.h"

#include "Leviathan/Platform/OpenGL/OpenGLRendererAPI.h"


namespace Leviathan {
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Unique<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateUnique<OpenGLRendererAPI>();
		}

		LE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}