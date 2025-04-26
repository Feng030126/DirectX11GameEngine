#pragma once
#include "GameObject.h"
class Character : public GameObject
{
protected:
	float mass = 10.0F;
	float speed = 30.0F;
	float jumpForce = 500.0F;
	float gravity = 5.0F;
	float friction = 0.7F;
	XMFLOAT2 velocity = { 0.0F, 0.0F };

	float rotation = 0.0F;
	float rotationSpeed = 0.0F;
	float radius = 0.0F;

public:
};

