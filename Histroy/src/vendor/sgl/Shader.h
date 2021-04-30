#pragma once
#include "SGL.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <unordered_map>
struct ShaderElements {
	std::string VertexShader;
	std::string FragmentShader;
};
class Shader
{
private: 
	unsigned int mRendererID;
	std::unordered_map<std::string, int> mUniformLocationCache;
public:
	Shader(std::string path);
	~Shader();

	unsigned int CreateProgram(const std::string& vertex, const std::string& fragment);
	unsigned int CompileShader(int type, const std::string& source);
	ShaderElements GetShaderSource(const std::string& path);

	int GetUniformLocation(const std::string& name);

	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
	void SetUniformMat4(const std::string& name, glm::mat4 matrix);

	void Bind();
	void Unbind();
};

