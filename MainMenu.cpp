#include "MainMenu.h"

void MainMenu::init(D3DX* d3dx, FrameTimer* frameTimer)
{
	frameTimer->init(60);

	HRESULT hr;

	spriteBatch.reset(new SpriteBatch(d3dx->getContext()));

	ComPtr<ID3D11Resource> texture;
	ComPtr<ID3D11ShaderResourceView> srv;

	hr = CreateWICTextureFromFile(
		d3dx->getDevice(),
		d3dx->getContext(),
		L"assets/start_game.png",
		texture.GetAddressOf(),
		srv.GetAddressOf()
	);

	if (FAILED(hr))
	{
		cout << "Failed to load texture" << endl;
		return;
	}

	Button startButton;

	startButton.setName("StartButton");
	startButton.setTexture(srv.Get());
	startButton.setPosition(100, 100);

	gameObjects.push_back(startButton);
 }

void MainMenu::update(D3DX*, stack<unique_ptr<GameState>>*, FrameTimer*)
{
	
}
