#pragma once
#include <GL/glew.h>
#include <iostream>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Buffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "Utilities.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>


#define ASSERT(x) if(x==0) __debugbreak();
#define GLCall(x) ErrorTools::GLClearError();\
	x;\
	ASSERT(ErrorTools::GLCheckError)

class ErrorTools
{
public:
	static inline void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	static inline void GLCheckError()
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error] (" << error << ") " << std::endl;
		}
	}
};