#pragma once

#include "GameObject.h"

class Font
{
private:
	wstring text;
	XMFLOAT2 position = { 0.0F, 0.0F };

public:
	void setText(wstring);
	void setPosition(float, float);
	wstring getText();
	XMFLOAT2 getPosition();
};

