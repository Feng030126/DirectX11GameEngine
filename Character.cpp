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

	hitBox.top = position.y;
	hitBox.bottom = hitBox.top + singleSpriteSize.y;
	hitBox.left = position.x;
	hitBox.right = hitBox.left + singleSpriteSize.x;

	return hitBox;
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
}

void Character::addOnStateEndListener(function<void(CharacterState state)> callback)
{
	onStateEnds.push_back(callback);
}

void Character::onStateEnd(CharacterState state)
{
	for(auto & fn : onStateEnds)
	{
		fn(state);
	}
}