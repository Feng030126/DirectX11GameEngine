#pragma once
#include "GameObject.h"

class Button : public GameObject
{
private:
	XMFLOAT2 size = { 0.0F,0.0F };
	enum { IDLE, HOVER, CLICKED };

public:
	void setSize(float, float);
	RECT hitBox();
	void setButtonState(int);
};

