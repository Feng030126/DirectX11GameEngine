#include "Gameplay.h"

void Gameplay::init(D3DX* d3dx, FrameTimer* timer)
{
	timer->init(30);

	spriteBatch.reset(new SpriteBatch(d3dx->getContext()));
	spriteFont.reset(new SpriteFont(d3dx->getDevice(), L"assets/orbitron.spritefont"));

	ComPtr<ID3D11ShaderResourceView> srv;

	createTexture(d3dx, "assets/grassBlock.png", &srv);

	blockPlatform_01 = new Block();

	blockPlatform_01->setName("Block");
	blockPlatform_01->setTexture(srv.Get());
	blockPlatform_01->setPosition(0, 728);
	blockPlatform_01->setSize(640, 32);
	blockPlatform_01->setSingleBlockSize(32);

	gameObjects.push_back(blockPlatform_01);

	blocks.push_back(blockPlatform_01);

	createTexture(d3dx, "assets/main_char.png", srv.GetAddressOf());

	mainCharacter = new Character();

	mainCharacter->setName("MainCharacter");
	mainCharacter->setTexture(srv.Get());
	mainCharacter->setPosition(30, 632);
	mainCharacter->setSize(128, 128);
	mainCharacter->setScale(0.5f);
	mainCharacter->setFrameCount(11, 12, 1);
	mainCharacter->setStartFrom(0, 12, 11);
	mainCharacter->setState(CharacterState::Idle);

	gameObjects.push_back(mainCharacter);

	createTexture(d3dx, "assets/cursor_sprite.png", srv.GetAddressOf());

	cursor = new Cursor();

	cursor->setName("Cursor");
	cursor->setTexture(srv.Get());
	cursor->setPosition(Input::getMousePos().x, Input::getMousePos().y);
	cursor->setSize(1, 1);

	gameObjects.push_back(cursor);

	ShowCursor(false);

}

void Gameplay::update(D3DX* d3dx, stack<unique_ptr<GameState>>* states, FrameTimer* timer)
{
	for (int i = 0; i < timer->framesToUpdate(); i++)
	{
		for (auto& block : blocks)
		{
			if (Physics::rectangleCollision(
				mainCharacter->getBottomHitBox(),
				block->hitBox()
			))
			{
				mainCharacter->setVelocityY(0); // Set the velocity to 0 to stop accumulating velocity
				mainCharacter->setPosition(
					XMVectorGetX(mainCharacter->getPosition()),
					block->hitBox().top - mainCharacter->getSize().y * mainCharacter->getScale()
				);
			}
		}

		if (Input::isKeyPressed('D'))
		{
			mainCharacter->applyForce({ mainCharacter->getSpeed(), 0 });
			mainCharacter->setState(Walking);
		}
		else
		{
			mainCharacter->setState(Idle);
		}

		mainCharacter->update();

		float currentXPos = Input::getMousePos().x;
		float currentYPos = Input::getMousePos().y;

		cursor->setPosition(Input::getMousePos().x, Input::getMousePos().y);

		if (Input::getMousePos().x < 0) currentXPos = 0;
		if (Input::getMousePos().x > WINDOW_WIDTH) currentXPos = WINDOW_WIDTH;
		if (Input::getMousePos().y < 0) currentYPos = 0;
		if (Input::getMousePos().y > WINDOW_HEIGHT) currentYPos = WINDOW_HEIGHT;

		Input::setMousePos(currentXPos, currentYPos);
	}
}

void Gameplay::cleanup()
{
	GameState::cleanup();

	cout << "Gameplay::cleanup()" << endl;

	blocks.clear();

	delete blockPlatform_01;
	delete cursor;
	delete mainCharacter;
}
