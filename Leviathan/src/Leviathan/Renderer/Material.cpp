#include "lpch.h"
#include "Material.h"

namespace Leviathan {


	void Material::Bind() 
	{
		if (m_Shader != nullptr)
			m_Shader->Bind();

		if (HasTexture()) {
			m_Texture->Bind();
			
		}
	}

	void Material::UnBind()
	{
		if (m_Shader != nullptr)
			m_Shader->Unbind();
	}

	/// ///////////////////
	/// UNIFORM SETTERS ///
	/// ///////////////////
	
	void Material::Set(const std::string& location, float uniform)
	{
		if (m_Shader == nullptr)
			return;
		m_Shader->SetFloat(location, uniform);
	}

	void Material::Set(const std::string& location, glm::vec2 uniform)
	{
		if (m_Shader == nullptr)
			return;
		m_Shader->SetVec2(location, uniform);
	}

	void Material::Set(const std::string& location, glm::vec3 uniform)
	{
		if (m_Shader == nullptr)
			return;

		m_Shader->SetVec3(location, uniform);
	}

	void Material::Set(const std::string& location, glm::vec4 uniform)
	{
		if (m_Shader == nullptr)
			return;

		m_Shader->SetVec4(location, uniform);
	}

	void Material::Set(const std::string& location, glm::mat3 uniform)
	{
		if (m_Shader == nullptr)
			return;

		m_Shader->SetMat3(location, uniform);
	}

	void Material::Set(const std::string& location, glm::mat4 uniform)
	{
		if (m_Shader == nullptr)
			return;

		m_Shader->SetMat4(location, uniform);
	}

	void Material::Set(const std::string& location, int uniform)
	{
		if (m_Shader == nullptr)
			return;

		m_Shader->SetInt(location, uniform);
	}

	void Material::Set(const std::string& location, int* uniform, uint32_t count)
	{
		if (m_Shader == nullptr)
			return;

		m_Shader->SetIntArray(location, uniform, count);

	}

}