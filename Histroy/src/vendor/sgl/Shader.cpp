#include "hspch.h"
#include "SGL.h"
Shader::Shader(std::string path)
{
	ShaderElements shaderSrc = GetShaderSource((const std::string&)path);
	mRendererID = CreateProgram(shaderSrc.VertexShader, shaderSrc.FragmentShader);
	Bind();
}

Shader::~Shader()
{
}

unsigned int Shader::CreateProgram(const std::string& vertex, const std::string& fragment)
{
	GLCall(unsigned int program = glCreateProgram());
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}

unsigned int Shader::CompileShader(int type, const std::string& source)
{
	GLCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " vertex " : " fragment ") << "shader! " << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

ShaderElements Shader::GetShaderSource(const std::string& path)
{
	enum class Type{NONE=-1, VERTEX=0, FRAGMENT=1};
	Type mode = Type::NONE;

	std::ifstream shader(path);
	std::stringstream ss[2];
	if (!shader)
	{
		std::cout << "Couldn't open file: " << path << std::endl;
		return { "", "" };
	}
	std::string line;
	while (std::getline(shader, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				mode = Type::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				mode = Type::FRAGMENT;
		}else
			ss[int(mode)] << line << "\n";
	}
	return { ss[0].str(), ss[1].str() };
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (mUniformLocationCache.find(name) != mUniformLocationCache.end())
		return mUniformLocationCache[name];
	GLCall(int location = glGetUniformLocation(mRendererID, name.c_str()));
	if (location == -1)
		std::cout << "Couldn't find uniform: " << name << std::endl;
	mUniformLocationCache[name] = location;
	return location;
}

void Shader::SetUniform1f(const std::string& name, float value)
{
	int location = GetUniformLocation(name);
	GLCall(glUniform1f(location, value));
}

void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4)
{
	GLCall(glUniform4f(GetUniformLocation(name), v1, v2, v3, v4));
}

void Shader::SetUniformMat4(const std::string& name, glm::mat4 matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

void Shader::Bind()
{
	GLCall(glUseProgram(mRendererID));
}

void Shader::Unbind()
{
	GLCall(glUseProgram(0));
}
