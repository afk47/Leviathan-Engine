#pragma once
#include "Camera.h"
#include "entt.hpp"
#include "Leviathan/Utils/Timestep.h"
namespace Leviathan {

	class Entity;
	
	class Scene {
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string & = std::string());
		void DestroyEntity(Entity entity);
		void SetCamera(PerspectiveCamera *camera) { m_Camera = camera; }
		void OnUpdate(Timestep ts);
		void OnViewportResize(uint32_t width, uint32_t height);
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);
	private:
		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
		PerspectiveCamera* m_Camera = nullptr;
		friend class Entity;
	};
}