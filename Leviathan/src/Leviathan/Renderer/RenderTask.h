#pragma once
#include "RendererAPI.h"

namespace Leviathan {
	
	class RenderTask {
	public:
		static void Init()
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->Init();
		}

		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->SetViewport(x, y, width, height);
		}

		static void SetClearColor(const glm::vec4& color)
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->SetClearColor(color);
		}

		static void Clear()
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->Clear();
		}

		static void DrawIndexed(const Ref<Mesh>& vertexArray, uint32_t indexCount = 0)
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->DrawIndexed(vertexArray, indexCount);
		}

		static void DrawLines(const Ref<Mesh>& vertexArray, uint32_t vertexCount)
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->DrawLines(vertexArray, vertexCount);
		}

		static void SetLineWidth(float width)
		{
			LE_PROFILE_FUNCTION();
			s_RendererAPI->SetLineWidth(width);
		}
	private:
		static Unique<RendererAPI> s_RendererAPI;
	};
}