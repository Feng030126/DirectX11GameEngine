#include "GameObject.h"

void GameObject::setPosition(float x, float y)
{
	position = { x,y };
}

XMFLOAT2 GameObject::getPosition()
{
	return position;
}
