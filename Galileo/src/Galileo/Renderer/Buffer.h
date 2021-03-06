#pragma once

namespace Galileo {
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {};
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);
	private:

	};
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {};
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	private:

	};
}