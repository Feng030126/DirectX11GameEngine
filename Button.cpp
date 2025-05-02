#include "Button.h"

void Button::setSize(float x, float y)
{
	size = { x, y };
}

RECT Button::hitBox()
{
	RECT hitBox;

	hitBox.top = XMVectorGetY(position);
	hitBox.bottom = hitBox.top + size.y;
	hitBox.left = XMVectorGetX(position);
	hitBox.right = hitBox.left + size.x;

	return hitBox;
}

void Button::setButtonState(int a)
{
	if (a == IDLE)
	{
		color = { 1.0F, 1.0F, 1.0F, 1.0F };
	}
	else if (a == HOVER)
	{
		color = { 0.7F, 0.7F, 0.7F, 0.7F };
	}
	else if (a == CLICKED)
	{
		color = { 0.5f, 0.5f,0.5f, 0.5F };
	}

	buttonState = static_cast<ButtonState>(a);
}

Button::ButtonState Button::getButtonState()
{
	return buttonState;
}
