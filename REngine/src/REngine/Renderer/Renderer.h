#pragma once
#include "RenderTask.h"

#include "Shader.h"
namespace REngine {



	class Renderer 
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<Mesh>& mesh);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	
	};

}