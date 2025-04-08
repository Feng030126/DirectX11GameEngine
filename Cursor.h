#pragma once
#include "GameObject.h"

class Cursor : public GameObject
{
private:
	XMFLOAT2 size = { 0.0F,0.0F };

public:
	void setSize(float, float);
	RECT hitBox();
};

