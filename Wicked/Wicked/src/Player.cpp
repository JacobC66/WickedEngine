#include "Player.h"

void Player::Start()
{
	const char* vS
	{
		"#version 430 core\n"
		"layout (location = 0) in vec3 vPos;\n"
		"uniform mat4 model;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = projection * model * vec4(vPos, 1.0f);\n"
		"}"
	};

	const char* fS
	{
		"#version 430 core\n"
		"out vec4 fColor;\n"
		"void main()\n"
		"{\n"
		"	fColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
		"}"
	};

	position = maths::Vector3(0.0f, 0.0f, 0.0f);

	shader.compile(vS, fS);
	std::vector<maths::Vector3> pos
	{
		maths::Vector3(-0.5f, -0.5f, 0.0f),
		maths::Vector3(0.5f, -0.5f, 0.0f),
		maths::Vector3(0.0f, 0.5f, 0.0f)
	};
	mesh.position = pos;
}

void Player::Update()
{
}

Player p;