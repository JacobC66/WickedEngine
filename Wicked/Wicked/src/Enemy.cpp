#include "Enemy.h"
#include "classes\Time.h"
#include "classes\Input.h"

const char* evS
{
	"#version 430 core\n"
	"layout (location = 0) in vec3 vPos;\n"
	"layout (location = 1) in vec2 vUV;\n"
	"layout (location = 2) in vec3 vNor;\n"
	"uniform mat4 model;\n"
	"uniform mat4 projection;\n"
	"out vec3 Nor;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = projection * model * vec4(vPos, 1.0f);\n"
	"	Nor = vNor;\n"
	"}"
};

const char* efS
{
	"#version 430 core\n"
	"in vec3 Nor;\n"
	"out vec4 fColor;\n"
	"void main()\n"
	"{\n"
	"	fColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
	"}"
};

std::vector<maths::Vector3> epos
{
	maths::Vector3(-2, -2, 0.0f),
	maths::Vector3(2, -2, 0.0f),
	maths::Vector3(0.0f, 2, 0.0f)
};

float espeed{ 6.5f };

void Enemy::Start()
{
	shader.compile(evS, efS);
	mesh.position = epos;
	position = maths::Vector3(6.0f, 0.0f, 0.0f);
}

void Enemy::Update()
{
}

Enemy e;