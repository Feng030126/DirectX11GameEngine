#pragma once
#include "GameState.h"

class MainMenu :
    public GameState
{
private:
    Button* startButton;
    Cursor* cursor;
    Font* title1;
    Font* title2;

public:
    void init(D3DX*, FrameTimer*);
    void update(D3DX*, stack<unique_ptr<GameState>>*, FrameTimer*);
    void cleanup() override;
};

