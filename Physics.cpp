#include "Physics.h"

bool Physics::rectangleCollision(RECT a, RECT b)
{
	if (a.top > b.bottom)
		return false;

	if (a.bottom < b.top)
		return false;

	if (a.left > b.right)
		return false;

	if (a.right < b.left)
		return false;

	return true;
}

bool Physics::sphereCollision(XMFLOAT2 p1, float r1, XMFLOAT2 p2, float r2)
{
	float rDistance = (r1 + r2) * (r1 + r2);
	float distance = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);

	if (rDistance > distance)
		return true;

	return false;
}
