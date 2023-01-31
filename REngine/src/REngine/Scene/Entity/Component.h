#pragma once


#include "REngine/Renderer/Mesh.h"
#include "REngine/Core/UUID.h"
#include "REngine/Renderer/Shader.h"
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

namespace REngine {

	struct Component{};

	struct IDComponent : Component 
	{
		UUID id;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
	};

	struct TransformComponent : Component
	{
		glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation =	{ 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale =		{ 1.0f, 1.0f, 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& translation)
			: Translation(translation) {}

		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation) * rotation * glm::scale(glm::mat4(1.0f), Scale);
		}
	};

	struct MeshComponent : Component
	{
		Mesh mesh;
		
		void Bind() { mesh.Bind(); }
		void UnBind() { mesh.UnBind(); }
	};

	struct MaterialComponent : Component
	{
		MaterialComponent() {};
		~MaterialComponent() {};

		Shader* Shader = nullptr;
		//Texture texture;
		void Bind() {};
	};

// 	template<typename T>
// 	struct CustomComponent : Component
// 	{
// 		std::string Name;
// 		CustomComponent(std::string name, vector<T> members) : Name(name) {}
// 	
// 		vector<T> CustomComponentMembers;
// 	};

	
}