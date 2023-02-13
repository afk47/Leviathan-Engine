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
		Shader(const std::string& vertexSrc = std::string(), const std::string& fragmentSrc = std::string());
		~Shader();

		void Bind() const;
		void Unbind() const;
		template<typename T> void Set(const std::string& name, T uniform, ShaderDataType type);
		virtual void SetInt(const std::string& name, int value);
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count);
		virtual void SetFloat(const std::string& name, float value);
		virtual void SetVec2(const std::string& name, const glm::vec2& value);
		virtual void SetVec3(const std::string& name, const glm::vec3& value);
		virtual void SetVec4(const std::string& name, const glm::vec4& value);
		virtual void SetMat3(const std::string& name, const glm::mat3& value);
		virtual void SetMat4(const std::string& name, const glm::mat4& value);

	private:
		uint32_t m_ShaderID;
	};

	
}