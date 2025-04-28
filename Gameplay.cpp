#include "Gameplay.h"

void Gameplay::init(D3DX* d3dx, FrameTimer* timer)
{
	timer->init(60);

	spriteBatch.reset(new SpriteBatch(d3dx->getContext()));
	spriteFont.reset(new SpriteFont(d3dx->getDevice(), L"assets/orbitron.spritefont"));

	cout << "Gameplay::init()" << endl;
}

void Gameplay::update(D3DX* d3dx, stack<unique_ptr<GameState>>* states, FrameTimer* timer)
{
	cout << "Gameplay::update()" << endl;
}

void Gameplay::cleanup()
{
	GameState::cleanup();

	cout << "Gameplay::cleanup()" << endl;
}
