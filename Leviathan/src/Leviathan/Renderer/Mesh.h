#pragma once

#include "Buffer.h"
#include <memory>

namespace Leviathan {

	class Mesh
	{
	public:
		virtual ~Mesh() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& VertexBuffer) = 0;

		virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() = 0;
		virtual Ref<IndexBuffer> GetIndexBuffer() = 0;

		static Mesh* Create();
		
	};


}