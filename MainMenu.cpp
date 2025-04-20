#include "MainMenu.h"

void MainMenu::init(D3DX* d3dx, FrameTimer* frameTimer)
{
	frameTimer->init(120);

	HRESULT hr;

	spriteBatch.reset(new SpriteBatch(d3dx->getContext()));

	ComPtr<ID3D11ShaderResourceView> srv;

	hr = CreateWICTextureFromFile(
		d3dx->getDevice(),
		d3dx->getContext(),
		L"assets/start_game.png",
		nullptr,
		srv.GetAddressOf()
	);

	if (FAILED(hr))
	{
		cout << "Failed to load texture" << endl;
		return;
	}

	startButton = new Button();

	startButton->setName("StartButton");
	startButton->setTexture(srv.Get());
	startButton->setPosition(810, 660);
	startButton->setSize(300,100);

	gameObjects.push_back(startButton);

	hr = CreateWICTextureFromFile(
		d3dx->getDevice(),
		d3dx->getContext(),
		L"assets/cursor_sprite.png",
		nullptr,
		srv.GetAddressOf()
	);

	if (FAILED(hr))
	{
		cout << "Failed to load texture" << endl;
		return;
	}

	cursor = new Cursor();

	cursor->setName("Cursor");
	cursor->setTexture(srv.Get());
	cursor->setPosition(Input::getMousePos().x, Input::getMousePos().y);
	cursor->setSize(1, 1);

	gameObjects.push_back(cursor);

	ShowCursor(false);
 }

void MainMenu::update(D3DX* d3dx, stack<unique_ptr<GameState>>* gameStates, FrameTimer* timer)
{
	for (int i = 0; i < timer->framesToUpdate(); i++) {

		startButton->setButtonState(0);
		cursor->setPosition(Input::getMousePos().x, Input::getMousePos().y);

		if(Physics::rectangleCollision(startButton->hitBox(), cursor->hitBox()))
		{
			startButton->setButtonState(1);

			if(Input::isMouseButtonPressed(0))
			{
				startButton->setButtonState(2);
			}
		}


	}
}

void MainMenu::cleanup()
{
	cout << "Cleaning up MainMenu" << endl;

	GameState::cleanup();

	delete startButton;
	delete cursor;

}
