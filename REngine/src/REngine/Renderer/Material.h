#pragma once

#include <vector>
#include "REngine/Core/Core.h"
#include "Shader.h"
#include "Texture.h"

namespace REngine {


	class Material {
	public:
		Material() {};
		~Material() {};

		inline virtual void SetShader(const Ref<Shader>& shader) { m_Shader = shader; }
		inline virtual void SetTexture(const Ref<Texture>& texture) { m_Texture = texture; }

		inline virtual Ref<Shader> GetShader() { return m_Shader; }
		inline virtual Ref<Texture> GetTexture() { return m_Texture; }

		inline virtual bool HasTexture() const { return m_Texture != nullptr; }
		
		virtual void Bind();
		virtual void UnBind();
		
		void Set(const std::string& location, float uniform);
		void Set(const std::string& location, glm::vec2 uniform);
		void Set(const std::string& location, glm::vec3 uniform);
		void Set(const std::string& location, glm::vec4 uniform);
		void Set(const std::string& location, glm::mat3 uniform);
		void Set(const std::string& location, glm::mat4 uniform);
		void Set(const std::string& location, int uniform);
		void Set(const std::string& location, int* uniform, uint32_t count);
	
		
	private:
		Ref<Shader> m_Shader;
		Ref<Texture> m_Texture;
	};


	class MaterialRef : Ref<Material>{};

	
}