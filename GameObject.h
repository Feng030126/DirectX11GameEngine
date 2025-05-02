#pragma once
#include "IHitbox.h"
#include <vector>

#define A

class GameObject
{
protected:
	string name = "";

	//Rendering data
	bool shouldRender = true;

	ComPtr<ID3D11ShaderResourceView> texture;
	RECT sourceRect = { 0,0,0,0 };
	XMVECTOR position = { 0,0 };
	XMVECTOR color = Colors::White;
	float rotation = 0;
	XMVECTOR origin = { 0,0 };
	float scale = 1;
	SpriteEffects effects = SpriteEffects_None;
	float layerDepth = 0;
	
public:
	void setPosition(float x, float y);
	XMVECTOR getPosition();
	void setColor(float r, float g, float b, float a);
	XMVECTOR getColor();
	void setTexture(ID3D11ShaderResourceView* srv);
	ID3D11ShaderResourceView* getTexture();
	void setRotation(float rad);
	float getRotation();
	void setOrigin(float x, float y);
	XMVECTOR getOrigin();
	void setScale(float scale);
	float getScale();
	void setSpriteEffects(SpriteEffects effects);
	SpriteEffects getSpriteEffects();
	void setLayerDepth(float layerDepth);
	float getLayerDepth();
	void setShouldRender(bool shouldRender);
	bool getShouldRender();
	void setName(string name);
	string getName();
	void setSourceRect(RECT sourceRect);
	RECT getSourceRect();

	virtual ~GameObject() = default;
};
