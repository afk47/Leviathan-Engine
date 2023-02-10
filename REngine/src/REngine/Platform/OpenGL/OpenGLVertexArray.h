#pragma once

#include "Rengine/Renderer/Buffer.h"
#include "REngine/Renderer/Mesh.h"
#include <memory>

namespace REngine {

	class OpenGLVertexArray : public Mesh
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& IndexBuffer) override;

		virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() override { return m_VertexBuffers; }
		virtual Ref<IndexBuffer> GetIndexBuffer() override { return m_IndexBuffer; }
	private:
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		uint32_t m_RendererID;
	};

	

}