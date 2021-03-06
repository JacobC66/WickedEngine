#pragma once
#include "classes\GameObject.h"

using namespace wicked;

class Player
	: public GameObject
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void CollisionEnter(const BoxCollider& object) override;
};