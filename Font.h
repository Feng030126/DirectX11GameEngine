#pragma once

#include "GameObject.h"

class Font : public GameObject
{
private:
	string text;
public:
	void setText(string text);
	string getText();
};

