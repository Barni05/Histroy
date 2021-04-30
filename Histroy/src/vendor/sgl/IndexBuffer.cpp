#include "hspch.h"
#include "IndexBuffer.h"
#include "SGL.h"
IndexBuffer::IndexBuffer(unsigned int count, unsigned int* indicies) : Buffer(count, indicies)
{
	GLCall(glGenBuffers(1, &mRendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indicies, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &mRendererID));
}

void IndexBuffer::SetData(unsigned int size, const void* data)
{
	Bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void IndexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
}

void IndexBuffer::Unbind()
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
