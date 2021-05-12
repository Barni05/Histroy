#include "hspch.h"
#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::DrawElements(Shader& shader, VertexArray& va, IndexBuffer& ib)
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::DrawArrays(Shader& shader, VertexArray& va, VertexBuffer& vb)
{
	shader.Bind();
	va.Bind();
	vb.Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
}

void Renderer::DrawPolygons(Shader& shader, VertexArray& va, IndexBuffer& ib)
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_POLYGON, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
