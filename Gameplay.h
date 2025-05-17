#pragma once
#include "GameState.h"

class Gameplay :  public GameState
{
private:
    Cursor* cursor;
    Character* mainCharacter;
    
    vector<Block*> blocks; //For collision detection loop
    Block* blockPlatform_01;

    //Timer doesn't need to be shared, so not pointer
    Timer jumpCooldown;
public:
    void init(D3DX&, FrameTimer&);
    void update(D3DX&, stack<unique_ptr<GameState>>&, FrameTimer&);
    void cleanup() override;
};

