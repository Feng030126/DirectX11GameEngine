#include "Block.h"

XMVECTOR Block::updateRenderPosition(float x, float y)
{
	XMVECTOR blockPos = position;
	
	blockPos = XMVectorSetX(blockPos, XMVectorGetX(blockPos) + x);
	blockPos = XMVectorSetY(blockPos, XMVectorGetY(blockPos) + y);

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

	hitBox.top = XMVectorGetY(position);
	hitBox.bottom = hitBox.top + size.y;
	hitBox.left = XMVectorGetX(position);
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
