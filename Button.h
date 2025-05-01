#pragma once
#include "GameObject.h"

class Button : public GameObject, public IHitbox
{
private:
	XMFLOAT2 size = { 0.0F,0.0F };
	enum ButtonState { IDLE, HOVER, CLICKED } buttonState;

public:
	void setSize(float, float) override;
	RECT hitBox() override;
	void setButtonState(int);
	ButtonState getButtonState();
};

