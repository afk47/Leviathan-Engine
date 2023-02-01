#pragma once

#include "Buffer.h"
#include <memory>

namespace REngine {

	class Mesh
	{
	public:
		virtual ~Mesh() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& IndexBuffer) = 0;

		virtual std::shared_ptr<VertexBuffer>& GetVertexBuffer() { return m_VertexBuffer; }
		virtual std::shared_ptr<IndexBuffer>& GetIndexBuffer() { return m_IndexBuffer; }
		
		static Mesh* Create();

	protected:
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};


}