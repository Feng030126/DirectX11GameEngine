#include "MainMenu.h"

void MainMenu::init(D3DX* d3dx, FrameTimer* frameTimer)
{
	frameTimer->init(60); // 60 FPS

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

	title1 = new Font();

	title1->setText("Another Platformer");
	title1->setPosition(800, 500);
	title1->setColor(Colors::Red.f[0], Colors::Red.f[1], Colors::Red.f[2], Colors::Red.f[3]);

	gameObjects.push_back(title1);

	title2 = new Font();

	title2->setText("That Have Gravity Gimmick");
	title2->setPosition(750, 550);
	title2->setColor(Colors::Blue.f[0], Colors::White.f[1], Colors::Pink.f[2], Colors::Red.f[3]);

	gameObjects.push_back(title2);

	hr = CreateWICTextureFromFile(
		d3dx->getDevice(),
		d3dx->getContext(),
		L"assets/main_char.png",
		nullptr,
		srv.GetAddressOf()
	);

	if (FAILED(hr))
	{
		cout << "Failed to load texture" << endl;
		return;
	}

	mainCharacter = new Character();

	mainCharacter->setName("MainCharacter");
	mainCharacter->setTexture(srv.Get());

	ShowCursor(false);
}

void MainMenu::update(D3DX* d3dx, stack<unique_ptr<GameState>>* gameStates, FrameTimer* timer)
{
	for (int i = 0; i < timer->framesToUpdate(); i++)
	{
		startButton->setButtonState(0);

		if (Physics::rectangleCollision(startButton->hitBox(), cursor->hitBox()))
		{
			startButton->setButtonState(1);

			if (Input::isMouseButtonPressed(0))
			{
				startButton->setButtonState(2);
			}
		}
	}

	float currentXPos = Input::getMousePos().x;
	float currentYPos = Input::getMousePos().y;

	cursor->setPosition(Input::getMousePos().x, Input::getMousePos().y);

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
	delete title1;
	delete title2;
	delete mainCharacter;

}
