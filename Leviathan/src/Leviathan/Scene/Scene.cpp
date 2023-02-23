#include "lpch.h"

#include "Scene.h"
#include "Entity.h"
#include "Component.h"

#include "Leviathan/Core/Application.h"
#include "Leviathan/Core/Layer.h"
#include "Leviathan/Renderer/Renderer.h"
#include "Leviathan/Utils/assimp/MeshLoader.h"

#include <glm/glm.hpp>


namespace Leviathan {

	

	Scene::Scene()
	{
		debugLayer = new DebugLayer();
		Application::Get().PushOverlay(debugLayer);
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

	void Scene::OnUpdate(Timestep ts) {
		LE_PROFILE_FUNCTION();
		//
		{
			Renderer::BeginScene();

			auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
			m_Camera->OnUpdate(ts);
			debugLayer->vertices = 0;
			debugLayer->draws = 0;
			for (auto entity : group)
			{
				LE_PROFILE_SCOPE("Entity Update");
				auto [transform, meshcomp] = group.get<TransformComponent, MeshComponent>(entity);
				meshcomp.material->Bind();
				meshcomp.material->Set("transformMatrix", transform.GetTransform());
				meshcomp.material->Set("projectionMatrix", m_Camera->GetViewProjectionMatrix());
				Renderer::Submit(meshcomp.material, meshcomp.mesh);
				
				debugLayer->vertices += meshcomp.mesh->GetIndexBuffer()->GetCount();
				debugLayer->draws++;
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

	std::vector<Entity> Scene::LoadMeshes(const std::string& path, Ref<Shader> shader) {

		LE_PROFILE_FUNCTION();
		std::vector<Entity> output = std::vector<Entity>();
		std::vector<MeshComponent> meshes = MeshLoader().LoadMeshes(path);
		for (auto mesh : meshes) {
			Entity entity = CreateEntity();
			mesh.material->SetShader(shader);
			entity.AddComponent<MeshComponent>(mesh);
			output.push_back(entity);

		}
		return output;
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
