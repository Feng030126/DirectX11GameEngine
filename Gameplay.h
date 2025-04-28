#pragma once
#include "GameState.h"

class Gameplay :  public GameState
{
public:
    void init(D3DX*, FrameTimer*);
    void update(D3DX*, stack<unique_ptr<GameState>>*, FrameTimer*);
    void cleanup() override;
};

