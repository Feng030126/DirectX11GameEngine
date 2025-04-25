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
	color = { r,g,b,a };
}

XMVECTOR GameObject::getColor()
{
	return color;
}

void GameObject::setTexture(ID3D11ShaderResourceView* srv)
{
	texture = srv;

	//By default, set the rect to full rect
	ID3D11Resource* resource = nullptr;

	texture->GetResource(&resource);

	ID3D11Texture2D* textureResource = nullptr;
	resource->QueryInterface<ID3D11Texture2D>(&textureResource);

	D3D11_TEXTURE2D_DESC desc;
	textureResource->GetDesc(&desc);

	sourceRect.left = 0;
	sourceRect.top = 0;
	sourceRect.right = desc.Width;
	sourceRect.bottom = desc.Height;

	resource->Release();
	textureResource->Release();
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

void GameObject::setIsFont(bool isFont)
{
	this->isFont = isFont;
}

bool GameObject::getIsFont()
{
	return isFont;
}

void GameObject::setSourceRect(RECT sourceRect)
{
	this->sourceRect = sourceRect;

}

RECT GameObject::getSourceRect()
{
	return sourceRect;
}
