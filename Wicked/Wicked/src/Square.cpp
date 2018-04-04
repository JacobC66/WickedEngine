#include <iostream>

#include "Square.h"

using namespace wicked;


Square::Square(const wicked::maths::Vector3& pos, const wicked::Mesh& mesh, const wicked::Shader& shader)
	:GameObject(pos, mesh, shader)
{
}

void Square::Start()
{
	//position = maths::Vector3(1.0f, 0.0f, 0.0f);
	
	//setRenderMesh(rm);
	renderMesh.init();
}

void Square::Update()
{
	renderMesh.draw();
}