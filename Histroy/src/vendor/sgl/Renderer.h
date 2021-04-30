#pragma once
#include "SGL.h"
class Shader;
class VertexArray;
class IndexBuffer;
class Renderer
{
public:
	Renderer();
	~Renderer();

	void DrawElements(Shader& shader, VertexArray& va, IndexBuffer& ib);
};

