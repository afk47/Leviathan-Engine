#pragma once
#include "Leviathan/Core/Core.h"

#include <string>
#include <glad/glad.h>

namespace Leviathan {

	class Texture {
	public:
		//Texture(uint32_t width, uint32_t height);
		Texture(const std::string& path);
		virtual ~Texture();
		
		virtual uint32_t GetWidth() const { return m_Width; }
		virtual uint32_t GetHeight() const { return m_Height; }
		virtual uint32_t GetRendererID() const { return m_RendererID; }
		virtual const std::string& GetPath() const { return m_Path; }
		virtual bool IsLoaded() const { return m_isLoaded; }

		virtual void SetData(void* data, uint32_t size);

		virtual void Bind(uint32_t slot = 0) const;

		virtual bool operator==(const Texture& other) const {
			return m_RendererID == other.GetRendererID();
		};
		
	private:
		std::string m_Path;
		bool m_isLoaded = false;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
		GLenum m_InternalFormat, m_DataFormat;
	};
}