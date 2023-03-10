#pragma once
#include "Leviathan/Renderer/Shader.h"
#include <Glad/glad.h>


namespace Leviathan {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;


		void SetInt(const std::string& name, int value);
		void SetIntArray(const std::string& name, int* values, uint32_t count);
		void SetFloat(const std::string& name, float value);
		void SetVec2(const std::string& name, const glm::vec2& value);
		void SetVec3(const std::string& name, const glm::vec3& value);
		void SetVec4(const std::string& name, const glm::vec4& value);

		void SetMat3(const std::string& name, const glm::mat3& matrix);
		void SetMat4(const std::string& name, const glm::mat4& matrix);
	private:

		void Compile(const std::unordered_map<GLenum, std::string>& shaderSources); 
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		
	private:
		uint32_t m_ShaderID;
	};
}