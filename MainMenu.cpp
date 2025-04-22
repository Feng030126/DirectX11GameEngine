#include "MainMenu.h"

void MainMenu::init(D3DX* d3dx, FrameTimer* frameTimer)
{
	HRESULT hr;

	spriteBatch.reset(new SpriteBatch(d3dx->getContext()));
	spriteFont.reset(new SpriteFont(d3dx->getDevice(), L"assets/orbitron.spritefont"));

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
	startButton->setSize(300, 100);

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

	title = new Font();

	title->setText(L"Some random platformer \n with gravity gimmick");
	title->setPosition(800, 500);

	fonts.push_back(title);

	ShowCursor(false);
}

void MainMenu::update(D3DX* d3dx, stack<unique_ptr<GameState>>* gameStates, FrameTimer* timer)
{

	startButton->setButtonState(0);

	float currentXPos = Input::getMousePos().x;
	float currentYPos = Input::getMousePos().y;

	cursor->setPosition(Input::getMousePos().x, Input::getMousePos().y);

	if (Physics::rectangleCollision(startButton->hitBox(), cursor->hitBox()))
	{
		startButton->setButtonState(1);

		if (Input::isMouseButtonPressed(0))
		{
			startButton->setButtonState(2);
		}
	}

	if (Input::getMousePos().x < 0) currentXPos = 0;
	if (Input::getMousePos().x > WINDOW_WIDTH) currentXPos = WINDOW_WIDTH;
	if (Input::getMousePos().y < 0) currentYPos = 0;
	if (Input::getMousePos().y > WINDOW_HEIGHT) currentYPos = WINDOW_HEIGHT;

	Input::setMousePos(currentXPos, currentYPos);

}

void MainMenu::cleanup()
{
	cout << "Cleaning up MainMenu" << endl;

	GameState::cleanup();

	delete startButton;
	delete cursor;
	delete title;

}
