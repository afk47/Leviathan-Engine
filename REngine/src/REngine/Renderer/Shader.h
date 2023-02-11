#pragma once

#include <string>

namespace REngine {

	class Shader
	{
	public:
		Shader(const std::string& vertexSrc = std::string(), const std::string& fragmentSrc = std::string());
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_ShaderID;
	};
}