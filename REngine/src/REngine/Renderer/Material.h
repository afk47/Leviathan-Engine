#pragma once

#include <vector>
#include "REngine/Core/Core.h"
#include "Shader.h"

namespace REngine {

	class Texture;

	class Material {
	public:
		Material() {};
		~Material() {};

		inline virtual void SetShader(const Ref<Shader>& shader) { m_Shader = shader; }
		inline virtual void SetTexture(const Ref<Texture>& texture) { m_Texture = texture; }

		inline virtual Ref<Shader> GetShader() { return m_Shader; }
		inline virtual Ref<Texture> GetTexture() { return m_Texture; }

	private:
		Ref<Shader> m_Shader;
		Ref<Texture> m_Texture;
	};


	class Texture {

		
	};
}