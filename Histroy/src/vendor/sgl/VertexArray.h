#pragma once
#include "SGL.h"
class VertexArray
{
private:
	unsigned int mRendererID;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(class VertexBuffer& vb, VertexBufferLayout& layout);

	void Bind();
	void Unbind();
};

