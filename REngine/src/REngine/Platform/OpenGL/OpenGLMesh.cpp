#include "repch.h"
#include "OpenGLMesh.h"

#include <glad/glad.h>

namespace REngine
{
	static GLenum ShaderDataTypeToOpenGL(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Vec2:	return GL_FLOAT;
		case ShaderDataType::Vec:	return GL_FLOAT;
		case ShaderDataType::Vec3:	return GL_FLOAT;
		case ShaderDataType::Vec4:	return GL_FLOAT;
		case ShaderDataType::Mat3:	return GL_FLOAT;
		case ShaderDataType::Mat4:	return GL_FLOAT;
		case ShaderDataType::Int2:	return GL_INT;
		case ShaderDataType::Int:	return GL_INT;
		case ShaderDataType::Int3:	return GL_INT;
		case ShaderDataType::Int4:	return GL_INT;
		case ShaderDataType::Bool:	return GL_BOOL;
		}
		RE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLMesh::OpenGLMesh()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLMesh::~OpenGLMesh()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLMesh::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLMesh::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLMesh::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		RE_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout");
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();


		uint32_t index = 0;
		for (const auto& element : vertexBuffer->GetLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, 
				element.GetComponentCount(), 
				ShaderDataTypeToOpenGL(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				vertexBuffer->GetLayout().GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffer = vertexBuffer;
	}

	void OpenGLMesh::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}

}