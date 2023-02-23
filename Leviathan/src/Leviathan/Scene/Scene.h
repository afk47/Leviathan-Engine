#pragma once
#include "Camera.h"
#include "entt.hpp"
#include "Leviathan/Utils/Timestep.h"
#include "Leviathan/Renderer/Shader.h"

#include "imgui.h"
#include "Leviathan/Core/Layer.h"
namespace Leviathan {

	class Entity;
	
	class DebugLayer;

	class Scene {
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string & = std::string());
		void DestroyEntity(Entity entity);
		void SetCamera(PerspectiveCamera *camera) { m_Camera = camera; }
		void OnUpdate(Timestep ts);
		void OnViewportResize(uint32_t width, uint32_t height);

		Entity LoadMesh(const std::string& path, Ref<Shader> shader);
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);
	private:
		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
		PerspectiveCamera* m_Camera = nullptr;
		DebugLayer* debugLayer;
		friend class Entity;
	};


	class DebugLayer : public Layer
	{
	public:

		DebugLayer() 
		{

		}
		void OnImGuiRender(Timestep ts)
		{
			std::string temp;
			ImGui::Begin("Debug");
			temp = "Draw Calls: " + std::to_string(draws);
			ImGui::Text(temp.c_str());
			temp = "Vertices: " + std::to_string(vertices);
			ImGui::Text(temp.c_str());
			temp = "Frametime: " + std::to_string(ts.GetMilliseconds()) + "ms (FPS " + std::to_string(1 / (ts.GetMilliseconds() * 0.001)) + ")";
			ImGui::Text(temp.c_str());
			ImGui::End();
		}

		uint32_t draws = 0;
		float frametime = 0.0f;
		float vertices = 0.0f;
	};
}