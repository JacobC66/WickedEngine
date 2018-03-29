#ifndef SHADER_H
#define SHADER_H

#include "Object.h"

namespace wicked
{
	class Shader
		: public Object
	{
	public:
		Shader(const char* shaderSource);
		~Shader();
	};
}

#endif