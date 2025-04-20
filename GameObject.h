#pragma once
#include "IHitbox.h"

class GameObject
{
protected:
	string name = "";

	//Rendering data
	bool shouldRender = true;

	ComPtr<ID3D11ShaderResourceView> texture;
	XMFLOAT2 position = { 0,0 };
	XMVECTOR color = Colors::White;
	float rotation = 0;
	XMFLOAT2 origin = { 0,0 };
	float scale = 1;
	SpriteEffects effects = SpriteEffects_None;
	float layerDepth = 0;
	

public:
	void setPosition(float x, float y);
	XMFLOAT2 getPosition();
	void setColor(float r, float g, float b, float a);
	XMVECTOR getColor();
	void setTexture(ID3D11ShaderResourceView* srv);
	ID3D11ShaderResourceView* getTexture();
	void setRotation(float rad);
	float getRotation();
	void setOrigin(float x, float y);
	XMFLOAT2 getOrigin();
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
};

