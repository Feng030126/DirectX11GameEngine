#include "Font.h"

void Font::setText(wstring set)
{
    text = set;
}

void Font::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

wstring Font::getText()
{
    return text;
}

XMFLOAT2 Font::getPosition()
{
    return position;
}
