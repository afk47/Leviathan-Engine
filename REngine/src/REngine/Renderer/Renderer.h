#pragma once
#include "RenderTask.h"
#include "Material.h"
namespace REngine {



	class Renderer 
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const Ref<Material>& material, const Ref<Mesh>& mesh);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	
	};

}