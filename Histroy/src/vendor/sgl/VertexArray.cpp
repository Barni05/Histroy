#include "hspch.h"
#include "VertexArray.h"
#include "SGL.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &mRendererID));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &mRendererID));
}

void VertexArray::AddBuffer(VertexBuffer& vb, VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	auto Elements = layout.GetElements();
	int offset = 0;
	for (int i = 0; i<Elements.size(); i++)
	{
		VertexElements Element = Elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, Element.count, Element.type, Element.bNormalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)offset))
		offset += Element.count * VertexBufferLayout::GetSizeByType(Element.type);
	}

}

void VertexArray::Bind()
{
	GLCall(glBindVertexArray(mRendererID));
}

void VertexArray::Unbind()
{
	GLCall(glBindVertexArray(0));
}
