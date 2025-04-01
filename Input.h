#pragma once

#include <Windows.h>
#include <iostream>
#include <DirectXMath.h>

using namespace DirectX;

class Input
{
private:
	static BYTE keys[256];
	static LONG currentMouseX, currentMouseY;
	static XMFLOAT3 mousePos;
	static bool mouseButton[3];

public:
	static void initialize(HWND hwnd);
	static void processInput(LPARAM lparam);
	static bool isKeyPressed(UINT key);
	static XMFLOAT3 getMousePos();
	static void setMousePos(LONG x, LONG y);
	static bool isMouseButtonPressed(int button);
};

