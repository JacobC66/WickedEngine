#include <iostream>
#include "Player.h"
#include "classes\Time.h"
#include "classes\Input.h"

const char* vS
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

const char* fS
{
	"#version 430 core\n"
	"in vec3 Nor;\n"
	"out vec4 fColor;\n"
	"void main()\n"
	"{\n"
	"	fColor = vec4(Nor, 1.0f);\n"
	"}"
};

std::vector<maths::Vector3> pos
{
	maths::Vector3(-2, -2, 0),
	maths::Vector3(2, -2, 0),
	maths::Vector3(2, 2, 0),
	maths::Vector3(2, 2, 0),
	maths::Vector3(-2, -2, 0),
	maths::Vector3(-2, 2, 0)
};
std::vector<maths::Vector3> nor
{
	maths::Vector3(1, 0, 1),
	maths::Vector3(0, 1, 1),
	maths::Vector3(1, 1, 0),
	maths::Vector3(1, 1, 0),
	maths::Vector3(1, 0, 1),
	maths::Vector3(0, 1, 1)
};

float speed{ 6.5f };

void Player::Start()
{
	tag = "Player";
	shader.compile(vS, fS);
	mesh.position = pos;
	mesh.normal = nor;
	position = maths::Vector3(0.0f, 0.0f, 0.0f);
	boxCollider.setSize(maths::Vector3(4.0f, 4.0f, 0.0f));
}

void Player::Update()
{
	boxCollider.setPosition(position);
	position.x += Input::getAxis("Horizontal") * Time::deltaTime * speed;
	position.y += Input::getAxis("Vertical") * Time::deltaTime * speed;
}

void Player::CollisionEnter(const BoxCollider& object)
{
	static int count{ 0 };
	if (object.gameObject->tag == "Enemy")
		object.gameObject->isDestroy = true;
}

Player p;