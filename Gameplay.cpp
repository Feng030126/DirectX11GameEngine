#include "Gameplay.h"

void Gameplay::init(D3DX* d3dx, FrameTimer* timer)
{
	timer->init(60);

	spriteBatch.reset(new SpriteBatch(d3dx->getContext()));
	spriteFont.reset(new SpriteFont(d3dx->getDevice(), L"assets/orbitron.spritefont"));

	ComPtr<ID3D11ShaderResourceView> srv;
	HRESULT hr;

	hr = CreateWICTextureFromFile(
		d3dx->getDevice(),
		d3dx->getContext(),
		L"assets/grassBlock.png",
		nullptr,
		srv.GetAddressOf()
	);

	if (FAILED(hr))
	{
		cout << "Failed to load texture" << endl;
		return;
	}

	test = new Block();

	test->setName("Block");
	test->setTexture(srv.Get());
	test->setPosition(0, 728);
	test->setSize(640, 32);
	test->setSingleBlockSize(32);

	gameObjects.push_back(test);

	ShowCursor(true);
}

void Gameplay::update(D3DX* d3dx, stack<unique_ptr<GameState>>* states, FrameTimer* timer)
{
}

void Gameplay::cleanup()
{
	GameState::cleanup();

	cout << "Gameplay::cleanup()" << endl;

	delete test;
}
