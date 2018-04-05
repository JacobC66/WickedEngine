#pragma once
#include "classes\GameObject.h"

using namespace wicked;

class Enemy
	: public GameObject
{
public:
	virtual void Start() override;
	virtual void Update() override;
};