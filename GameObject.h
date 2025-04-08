#pragma once
#include "FrameTimer.h"

class GameObject
{
protected:
	XMMATRIX matrix;
	XMFLOAT2 position;

public:
	void setPosition(float x, float y);
	XMFLOAT2 getPosition();
};

