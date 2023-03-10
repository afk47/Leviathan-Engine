#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Leviathan/Renderer/Mesh.h"
#include "Leviathan/Renderer/Material.h"

namespace Leviathan {

	
	///	Components Entity Component System - DATA ONLY.
	
	struct TagComponent // Entity Name / Identifier
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}
	};

	struct TransformComponent // Entity Position Rotation and Scale 
	{
		glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3 & translation)
			: Translation(translation) {}



		//Creates transform matrix
		glm::mat4 GetTransform() const
		{
			LE_PROFILE_FUNCTION();
			glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), Rotation.x, { 1, 0, 0 })
				* glm::rotate(glm::mat4(1.0f), Rotation.y, { 0, 1, 0 })
				* glm::rotate(glm::mat4(1.0f), Rotation.z, { 0, 0, 1 });

			return glm::translate(glm::mat4(1.0f), Translation)
				* rotation
				* glm::scale(glm::mat4(1.0f), Scale);
		}
	};

	struct MeshComponent // Mesh component (required for renderable)
	{
		Ref<Mesh> mesh;
		Ref<Material> material;

		MeshComponent()
		{
			LE_CORE_TRACE("MESH CREATED");
			mesh.reset(Mesh::Create());
			material.reset(new Material());
		}
		~MeshComponent() {
			
			LE_CORE_TRACE("MESH DESTROYED");
		}
		
	};

	struct ParentEntityComponent 
	{
		Ref<Entity> Parent;
	};

	struct ChildrenComponent 
	{
		Ref<std::vector<Ref<Entity>>> Children;

		uint32_t NumChildren()
		{
			return (uint32_t)Children->size();
		}
	};

	struct CameraComponent
	{
		Ref<PerspectiveCamera> camera;

	};
};