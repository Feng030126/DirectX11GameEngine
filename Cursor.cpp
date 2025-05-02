#include "Cursor.h"

void Cursor::setSize(float x, float y)
{
    size = { x,y };
}

RECT Cursor::hitBox()
{
	RECT hitBox;

	hitBox.top = XMVectorGetY(position);
	hitBox.bottom = hitBox.top + size.y;
	hitBox.left = XMVectorGetX(position);
	hitBox.right = hitBox.left + size.x;

	return hitBox;
}
