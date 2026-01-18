#include "lpch.h"
#include "Shader.h"
#include "Leviathan/Platform/OpenGL/OpenGLShader.h"
#include "Renderer.h"

#include <glad/glad.h>

namespace Leviathan {

	Shader* Shader::Create(const std::string& filepath)
	{
		LE_PROFILE_FUNCTION();
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLShader(filepath);
		}

		LE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	
}