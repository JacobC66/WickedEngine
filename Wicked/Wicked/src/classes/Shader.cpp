#include <glad\glad.h>
#include <iostream>
#include "Shader.h"

namespace wicked
{
	Shader::Shader()
	{
	}

	Shader::Shader(const char* vertex, const char* fragment)
	{
		compile(vertex, fragment);
	}

	void Shader::compile(const char* vertexSource, const char* fragmentSource)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSource, nullptr);
		glCompileShader(vertexShader);
		shaderError(vertexShader, "VERTEX");

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
		glCompileShader(fragmentShader);
		shaderError(fragmentShader, "FRAGMENT");

		m_program = glCreateProgram();
		glAttachShader(m_program, vertexShader);
		glAttachShader(m_program, fragmentShader);
		glLinkProgram(m_program);
		shaderError(m_program, "PROGRAM");

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void Shader::use() const
	{
		glUseProgram(m_program);
	}

	void Shader::setVector3(const char* name, const maths::Vector3& vec3) const
	{
		glUniform3fv(glGetUniformLocation(m_program, name), 1, &vec3[0]);
	}

	void Shader::setVector4(const char* name, const maths::Vector4& vec4) const
	{
		glUniform4fv(glGetUniformLocation(m_program, name), 1, &vec4[0]);
	}

	void Shader::setMatrix4x4(const char* name, const maths::Matrix4x4& mat4x4, bool transpose) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_program, name), 1, transpose, &mat4x4[0][0]);
	}

	void Shader::shaderError(unsigned int shader, const char* type)
	{
		int success;
		char infoLog[512];

		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 512, nullptr, infoLog);
				std::cout << type << "_SHADER_ERROR:\n" << infoLog << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 512, nullptr, infoLog);
				std::cout << type << "_SHADER_ERROR:\n" << infoLog << std::endl;
			}
		}

	}

	Shader::~Shader()
	{
		glDeleteProgram(m_program);
	}
}