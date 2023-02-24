#pragma once

#include <vector>
#include "Leviathan/Core/Core.h"
#include "Shader.h"
#include "Texture.h"

namespace Leviathan {

	struct MTL;

	class Material {
	public:
		Material() {};
		~Material() {};

		inline virtual void SetShader(const Ref<Shader>& shader) { m_Shader = shader; }
		inline virtual void SetTexture(const Ref<Texture>& texture) { m_Texture = texture; }
		inline virtual void SetMTL(const Ref<MTL>& MTL) { m_MTL = MTL; }

		inline virtual Ref<Shader> GetShader() { return m_Shader; }
		inline virtual Ref<Texture> GetTexture() { return m_Texture; }
		inline virtual Ref<MTL> GetMTL() { return m_MTL; }

		inline virtual bool HasTexture() const { return m_Texture != nullptr; }
		inline virtual bool HasMTL() const { return m_MTL != nullptr; }

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
		Ref<MTL> m_MTL;
	};


	struct MTL
	{			// MATERIAL INFORMATION 
		MTL()
		{
			name;
			Ns = 0.0f;
			Ni = 0.0f;
			d = 0.0f;
			illum = 0;
		}

		// Material Name
		std::string name;
		// Ambient Color
		glm::vec3 Ka;
		// Diffuse Color
		glm::vec3 Kd;
		// Specular Color
		glm::vec3 Ks;
		// Specular Exponent
		float Ns;
		// Optical Density
		float Ni;
		// Dissolve
		float d;
		// Illumination
		int illum;
		// Ambient Texture Map
		std::string map_Ka;
		// Diffuse Texture Map
		std::string map_Kd;
		// Specular Texture Map
		std::string map_Ks;
		// Specular Hightlight Map
		std::string map_Ns;
		// Alpha Texture Map
		std::string map_d;
		// Bump Map
		std::string map_bump;
	};

	
}