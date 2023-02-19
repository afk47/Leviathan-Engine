#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace REngine {

	enum class ShaderDataType
	{
		None = 0,
		Float, Vec2, Vec3, Vec4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool
	};

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;


		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetVec2(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetVec3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetVec4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetMat3(const std::string& name, const glm::mat3& value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

	
}