#include "Block.h"

XMFLOAT2 Block::updateRenderPosition(float x, float y)
{
	XMFLOAT2 blockPos = position;
	blockPos.x += x;
	blockPos.y += y;

	return blockPos;
}

void Block::setSize(float x, float y)
{
	size.x = x;
	size.y = y;
}

RECT Block::hitBox()
{
	RECT hitBox;

	hitBox.top = position.y;
	hitBox.bottom = hitBox.top + size.y;
	hitBox.left = position.x;
	hitBox.right = hitBox.left + size.x;

	return hitBox;
}

void Block::renderBlock(SpriteBatch* sb)
{
	for (int x = 0; x < size.x; x += singleBlockSize)
	{
		for (int y = 0; y < size.y; y += singleBlockSize)
		{
			renderPosition = updateRenderPosition(x, y);

			sb->Draw(
				texture.Get(),
				renderPosition,
				&sourceRect,
				color,
				rotation,
				origin,
				scale,
				effects,
				layerDepth
			);

		}
	}
}

void Block::setSingleBlockSize(float size)
{
	this->singleBlockSize = size;
}
