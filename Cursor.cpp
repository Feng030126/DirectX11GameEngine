#include "Cursor.h"

void Cursor::setSize(float x, float y)
{
    size = { x,y };
}

RECT Cursor::hitBox()
{
	RECT hitBox;

	hitBox.top = position.y;
	hitBox.bottom = hitBox.top + size.y;
	hitBox.left = position.x;
	hitBox.right = hitBox.left + size.x;

	return hitBox;
}
