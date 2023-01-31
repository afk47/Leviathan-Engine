#pragma once
#include "Camera.h"
#include "Mesh.h"
#include "Shader.h"


namespace REngine {

	enum class RendererAPI
	{
		None = 0, 
		OpenGL
	};

	class Renderer 
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void SetCamera(OrthographicCamera& camera) { m_Camera = camera; }
		static void Clear();

		static void Render(std::shared_ptr<Shader> shader, std::shared_ptr<Mesh> mesh);
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static OrthographicCamera m_Camera;
		static RendererAPI s_RendererAPI;
	};

}