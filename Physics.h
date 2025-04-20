#pragma once

#include <Windows.h>
#include <DirectXMath.h>

using namespace DirectX;

class Physics
{
public:
	static bool rectangleCollision(RECT a, RECT b);
	static bool sphereCollision(XMFLOAT2 a, float aRadius, XMFLOAT2 b, float bRadius);
};

