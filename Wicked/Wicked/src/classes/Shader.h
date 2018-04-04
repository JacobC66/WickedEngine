#ifndef SHADER_H
#define SHADER_H

#include "maths\Vector3.h"
#include "maths\Vector4.h"
#include "maths\Matrix4x4.h"

namespace wicked
{
	class Shader
	{
	public:
		unsigned int m_program;

	public:
		Shader();
		Shader(const Shader& shader);
		Shader(const char* vertex, const char* fragment);
		void compile(const char* vertexSource, const char* fragmentSource);
		void use();
		void setVector3(const char* name, const maths::Vector3& vec3);
		void setVector4(const char* name, const maths::Vector4& vec4);
		void setMatrix4x4(const char* name, const maths::Matrix4x4& matrix4x4, bool transpose);
		~Shader();

	private:
		void shaderError(unsigned int shader, const char* type);

	};
}

#endif