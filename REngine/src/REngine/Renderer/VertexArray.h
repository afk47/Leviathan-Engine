#pragma once

#include "Buffer.h"
#include <memory>

namespace REngine {

	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& VertexBuffer) = 0;

		static VertexArray* Create();
		
	};


}