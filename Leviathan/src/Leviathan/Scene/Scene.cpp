#include "lpch.h"

#include "Scene.h"
#include "Entity.h"
#include "Component.h"

#include "Leviathan/Core/Application.h"
#include "Leviathan/Core/Layer.h"
#include "Leviathan/Renderer/Renderer.h"
#include "Leviathan/Utils/MeshLoaders/MeshLoader.h"

#include <glm/glm.hpp>


namespace Leviathan {

	

	Scene::Scene()
	{
		debugLayer = new DebugLayer();
		Application::Get().PushOverlay(debugLayer);
	}

	Scene::~Scene() {

	}

	void Scene::OnUpdate(Timestep ts) {
		LE_PROFILE_FUNCTION();
	
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
				meshcomp.material->Set("viewPos", m_Camera->GetPosition());

				if (meshcomp.material->HasMTL()) {
					Ref<MTL> mtl = meshcomp.material->GetMTL();

					meshcomp.material->Set("material.ambient",mtl->Ka);
					meshcomp.material->Set("material.diffuse",mtl->Kd);
					meshcomp.material->Set("material.specular", mtl->Ks);
					meshcomp.material->Set("material.shininess", mtl->Ns);
					meshcomp.material->Set("material.Ni", mtl->Ni);
					meshcomp.material->Set("material.d", mtl->d);
					meshcomp.material->Set("material.illum", mtl->illum);
				}


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

	Entity Scene::LoadMesh(const std::string& path, Ref<Shader> shader) {

		LE_PROFILE_FUNCTION();
		
		MeshComponent mesh = MeshLoader().LoadMeshes(path);

		//for (MeshComponent mesh : meshes) {
			Entity entity = CreateEntity("entity");
			mesh.material->SetShader(shader);
			mesh.material->Bind();
			mesh.mesh->Bind();
			entity.AddComponent<MeshComponent>(mesh);
			//output.push_back(entity);

	//	}
		return entity;
	}

	//Methods for when specific components are added
	template<typename T>
	void Scene::OnComponentAdded(Entity entity, T& component)
	{
	}

	template<>
	void Scene::OnComponentAdded<MeshComponent>(Entity entity, MeshComponent& component)
	{
	}
	
}
