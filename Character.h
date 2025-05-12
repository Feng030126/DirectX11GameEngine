#pragma once
#include "GameObject.h"
#include <functional>

enum CharacterState
{
	Idle,
	Walking,
	Jumping
};

class Character : public GameObject, public IHitbox
{
private:
	CharacterState state = Idle;

	float mass = 10.0F;
	float speed = 30.0F;
	float jumpForce = 500.0F;
	XMVECTOR gravity = { 0,5.0f };
	float friction = 0.7F;
	XMVECTOR velocity = { 0.0F, 0.0F };
	XMVECTOR acceleration = { 0.0F, 0.0F };
	XMVECTOR moveForce = { 0.0F, 0.0F };

	float rotation = 0.0F;
	float rotationSpeed = 0.0F;
	float radius = 0.0F;

	XMFLOAT2 singleSpriteSize = {0.0F,0.0F};

	int currentFrame = 0; //On switch state => reset to 0, use to calculate rect on sprite sheet

	int idleFrameCount = 1;
	int walkingFrameCount = 1;
	int jumpingFrameCount = 1;

	//the spritesheet provided should only have one row
	int idleStartFrom = 0;
	int walkingStartFrom = 0;
	int jumpingStartFrom = 0;

	void calculateSourceRect();
	void onStateEnd(CharacterState state);
	vector<function<void(CharacterState state)>> onStateEnds;

public:
	void setSize(float x, float y) override;
	RECT hitBox() override;

	//Individual hitboxes for each side of the character
	RECT getBottomHitBox();
	RECT getTopHitBox();
	RECT getLeftHitBox();
	RECT getRightHitBox();

	XMFLOAT2 getSize();

	void setState(CharacterState state);
	CharacterState getState();

	/// <summary>
	/// Set the total number of frames for each state.
	/// </summary>
	/// <param name="idle">: Idle state</param>
	/// <param name="walking">: Walking/Moving state</param>
	/// <param name="jumping">: Jumping state</param>
	void setFrameCount(int idle, int walking, int jumping);

	/// <summary>
	/// Set the starting frame for each state, in the sprite sheet.
	/// </summary>
	/// <param name="idle">: Idle state</param>
	/// <param name="walking">: Walking/Moving state</param>
	/// <param name="jumping">: Jumping state</param>
	void setStartFrom(int idle, int walking, int jumping);

	void update();

	void addOnStateEndListener(function<void(CharacterState state)> callback);

	void setGravity(float g);

	void applyForce(XMVECTOR force);

	float getSpeed();

	//For case where collision is detected, manually set the velocity to 0 so it doesn't accumulate
	void setVelocityX(float);
	void setVelocityY(float);
};

