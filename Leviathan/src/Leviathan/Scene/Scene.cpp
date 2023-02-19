#include "lpch.h"

#include "Scene.h"
#include "Entity.h"
#include "Component.h"

#include "Leviathan/Renderer/Renderer.h"

#include <glm/glm.hpp>

namespace Leviathan {

	Scene::Scene()
	{

	}

	Scene::~Scene() {

	}

	Entity Scene::CreateEntity(const std::string& name) {

		LE_PROFILE_FUNCTION();
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}


	void Scene::DestroyEntity(Entity entity) {
		m_Registry.destroy(entity);
	}

	void Scene::OnUpdate() {
		LE_PROFILE_FUNCTION();
		{
			Renderer::BeginScene();

			auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
			m_Camera->OnUpdate();
			for (auto entity : group)
			{
				LE_PROFILE_SCOPE("Entity");
				auto [transform, meshcomp] = group.get<TransformComponent, MeshComponent>(entity);
				meshcomp.material->Bind();
				meshcomp.material->Set("transformMatrix", transform.GetTransform());
				meshcomp.material->Set("projectionMatrix", m_Camera->GetViewProjectionMatrix());
				Renderer::Submit(meshcomp.material, meshcomp.mesh);
			}
			Renderer::EndScene();
		}
	}

	void Scene::OnViewportResize(uint32_t width, uint32_t height)
	{
		LE_PROFILE_FUNCTION();
		m_ViewportWidth = width;
		m_ViewportHeight = height;

		// Resize our non-FixedAspectRatio cameras
// 		auto view = m_Registry.view<CameraComponent>();
// 		for (auto entity : view)
// 		{
// 			auto& cameraComponent = view.get<CameraComponent>(entity);
// 			if (!cameraComponent.FixedAspectRatio)
// 				cameraComponent.Camera.SetViewportSize(width, height);
// 		}
	}



	//Methods for when components are added
	template<typename T>
	void Scene::OnComponentAdded(Entity entity, T& component)
	{
	}

	template<>
	void Scene::OnComponentAdded<MeshComponent>(Entity entity, MeshComponent& component)
	{
	}
	
}
