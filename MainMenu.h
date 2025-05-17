#pragma once
#include "Gameplay.h"

class MainMenu :
    public GameState
{
private:
    Button* startButton;
    Cursor* cursor;
    Font* title1;
    Font* title2;

    Character* mainCharacter;

    void changeCharacterState(CharacterState state);

public:
    void init(D3DX&, FrameTimer&);
    void update(D3DX&, stack<unique_ptr<GameState>>&, FrameTimer&);
    void cleanup() override;
};

