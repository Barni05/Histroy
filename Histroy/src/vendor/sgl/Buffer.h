#pragma once
class Buffer
{
protected:
	unsigned int mRendererID;
	unsigned int mSize;

public:
	Buffer(unsigned int mSize, const void* data);
	~Buffer();

	virtual void Bind() = 0;
	virtual void Unbind() = 0;
	virtual void SetData(unsigned int size, const void* data) = 0;
};

