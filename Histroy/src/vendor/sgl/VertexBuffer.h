#pragma once
#include "SGL.h"
#include "Buffer.h"
class VertexBuffer : public Buffer
{
public:
	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	/// Sets a new data set to the Index Buffer
	void SetData(unsigned int size, const void* data);

	/// Bind the buffer
	void Bind();

	/// Unbind the buffer
	void Unbind();
};

