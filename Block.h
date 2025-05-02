#pragma once
#include "GameObject.h"

class Block : public GameObject, public IHitbox
{
private:
	//In the situation of block, size determines the length of platform
	XMFLOAT2 size;
	XMVECTOR renderPosition; // The position where the block will be rendered

	float singleBlockSize = 1.0f; // The size of a single block in the grid

	XMVECTOR updateRenderPosition(float x, float y);

public:
	void setSize(float, float) override;
	RECT hitBox() override;

	void renderBlock(SpriteBatch* sb);

	void setSingleBlockSize(float size);
};