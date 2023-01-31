#pragma once

#include "Rengine/Renderer/Buffer.h"
#include "REngine/Renderer/Mesh.h"
#include <memory>

namespace REngine {

	class OpenGLMesh : public Mesh
	{
	public:
		OpenGLMesh();
		virtual ~OpenGLMesh();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& IndexBuffer) override;

	private:
		std::shared_ptr<VertexBuffer> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		uint32_t m_RendererID;
	};

	

}