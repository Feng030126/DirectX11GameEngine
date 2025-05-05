#include "Character.h"

void Character::calculateSourceRect()
{
	RECT newRect;

	//Since we have one row, this is fixed
	newRect.top = 0;
	newRect.bottom = singleSpriteSize.y;

	if (state == Idle)
	{
		newRect.left = (idleStartFrom + currentFrame % idleFrameCount) * singleSpriteSize.x;

		if(currentFrame % idleFrameCount == 0)
		{
			currentFrame = 0; 
			onStateEnd(state); // Call the state end function
		}
	}
	else if (state == Walking)
	{
		newRect.left = (walkingStartFrom + currentFrame % walkingFrameCount) * singleSpriteSize.x;

		if (currentFrame % walkingFrameCount == 0)
		{
			currentFrame = 0; 
			onStateEnd(state); // Call the state end function
		}
	}
	else if (state == Jumping)
	{
		newRect.left = (jumpingStartFrom + currentFrame % jumpingFrameCount) * singleSpriteSize.x;

		if (currentFrame % jumpingFrameCount == 0)
		{
			currentFrame = 0;
			onStateEnd(state); // Call the state end function
		}
	}

	newRect.right = newRect.left + singleSpriteSize.x;

	sourceRect = newRect;
}

void Character::setSize(float x, float y)
{
	singleSpriteSize.x = x;
	singleSpriteSize.y = y;
}

RECT Character::hitBox()
{
	RECT hitBox;

	hitBox.top = XMVectorGetY(position);
	hitBox.bottom = hitBox.top + singleSpriteSize.y;
	hitBox.left = XMVectorGetX(position);
	hitBox.right = hitBox.left + singleSpriteSize.x;

	return hitBox;
}

RECT Character::getBottomHitBox()
{
	RECT hitbox;

	hitbox.left = XMVectorGetX(position) + singleSpriteSize.x * scale * 0.2;
	hitbox.right = hitbox.left + singleSpriteSize.x * scale * 0.6;
	hitbox.top = XMVectorGetY(position) + singleSpriteSize.y * scale * 0.8;
	hitbox.bottom = hitbox.top + singleSpriteSize.y * scale;

	return hitbox;
}

RECT Character::getTopHitBox()
{
	return RECT();
}

RECT Character::getLeftHitBox()
{
	return RECT();
}

RECT Character::getRightHitBox()
{
	return RECT();
}

XMFLOAT2 Character::getSize()
{
	return singleSpriteSize;
}

void Character::setState(CharacterState state)
{
	this->state = state;

	currentFrame = 0; // Reset to 0 on state change
}

CharacterState Character::getState()
{
	return state;
}

void Character::setFrameCount(int idle, int walking, int jumping)
{
	idleFrameCount = idle;
	walkingFrameCount = walking;
	jumpingFrameCount = jumping;
}

void Character::setStartFrom(int idle, int walking, int jumping)
{
	idleStartFrom = idle;
	walkingStartFrom = walking;
	jumpingStartFrom = jumping;
}

void Character::update()
{
	currentFrame++;

	calculateSourceRect();

	//Physics
	acceleration = moveForce / mass;

	velocity += acceleration;

	velocity += gravity;

	position += velocity;

	velocity = XMVectorSetX(velocity, XMVectorGetX(velocity) * friction);
}

void Character::addOnStateEndListener(function<void(CharacterState state)> callback)
{
	onStateEnds.push_back(callback);
}

void Character::setGravity(float g)
{
	gravity = XMVectorSetY(gravity, g);
}

void Character::applyForce(XMVECTOR force)
{
	this->moveForce += force;
}

float Character::getSpeed()
{
	return speed;
}

void Character::onStateEnd(CharacterState state)
{
	for(auto & fn : onStateEnds)
	{
		fn(state);
	}
}