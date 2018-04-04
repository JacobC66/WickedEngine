#pragma once

#include "classes/GameObject.h"

class Square
	: public wicked::GameObject
{
public:
	Square(const wicked::maths::Vector3& pos, const wicked::Mesh& mesh, const wicked::Shader& shader);
	virtual void Start() override;
	virtual void Update() override;
};

