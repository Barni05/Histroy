#pragma once
#include "SGL.h"
#include "Buffer.h"
class Buffer;
class IndexBuffer : public Buffer
{
private:
public:
	IndexBuffer(unsigned int count, unsigned int* indicies);
	~IndexBuffer();

	/// Sets a new data set to the Index Buffer
	void SetData(unsigned int size, const void* data);

	unsigned int GetCount() { return mSize; }

	void Bind();
	void Unbind();
};

