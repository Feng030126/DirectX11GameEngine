#include "GameObject.h"

void GameObject::setPosition(float x, float y)
{
	position = { x,y };
}

XMFLOAT2 GameObject::getPosition()
{
	return position;
}

void GameObject::setColor(float r, float g, float b, float a)
{
	color = {r,g,b,a};
}

XMVECTOR GameObject::getColor()
{
	return color;
}

void GameObject::setTexture(ID3D11ShaderResourceView* srv)
{
	texture = srv;
}

ID3D11ShaderResourceView* GameObject::getTexture()
{
	return texture.Get();
}

void GameObject::setRotation(float rad)
{
	rotation = rad;
}

float GameObject::getRotation()
{
	return rotation;
}

void GameObject::setOrigin(float x, float y)
{
	origin = { x, y };
}

XMFLOAT2 GameObject::getOrigin()
{
	return origin;
}

void GameObject::setScale(float scale)
{
	this->scale = scale;
}

float GameObject::getScale()
{
	return scale;
}

void GameObject::setSpriteEffects(SpriteEffects effects)
{
	this->effects = effects;
}

SpriteEffects GameObject::getSpriteEffects()
{
	return effects;
}

void GameObject::setLayerDepth(float layerDepth)
{
	this->layerDepth = layerDepth;
}

float GameObject::getLayerDepth()
{
	return layerDepth;
}

void GameObject::setShouldRender(bool shouldRender)
{
	this->shouldRender = shouldRender;
}

bool GameObject::getShouldRender()
{
	return shouldRender;
}

void GameObject::setName(string name)
{
	this->name = name;
}

string GameObject::getName()
{
	return name;
}
