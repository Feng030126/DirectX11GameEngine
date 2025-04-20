#pragma once
#include "GameObject.h"

class Cursor : public GameObject, public IHitbox
{
private:
	XMFLOAT2 size = { 0.0F,0.0F };

public:
	void setSize(float, float) override;
	RECT hitBox() override;
};

