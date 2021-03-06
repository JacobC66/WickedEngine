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
	"	fColor = vec4(Nor, 1.0f);\n"
	"}"
};

std::vector<maths::Vector3> epos
{
	maths::Vector3(-2, -2, 0),
	maths::Vector3(2, -2, 0),
	maths::Vector3(2, 2, 0),
	maths::Vector3(2, 2, 0),
	maths::Vector3(-2, -2, 0),
	maths::Vector3(-2, 2, 0)
};
std::vector<maths::Vector3> enor
{
	maths::Vector3(1, 0, 0),
	maths::Vector3(0, 0, 1),
	maths::Vector3(0, 1, 0),
	maths::Vector3(0, 1, 0),
	maths::Vector3(1, 0, 0),
	maths::Vector3(0, 0, 1)
};

float espeed{ 6.5f };

void Enemy::Start()
{
	tag = "Enemy";
	shader.compile(evS, efS);
	mesh.position = epos;
	mesh.normal = enor;
	position = maths::Vector3(6.0f, 7.0f, 0.0f);
	boxCollider.setSize(maths::Vector3(2.0f, 2.0f, 0.0f));
	boxCollider.setPosition(position);
}

void Enemy::Update()
{
}

Enemy e;