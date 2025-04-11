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

	Sprite sprite;
	sprite.name = "button_start";
	sprite.texture = move(texture);
	sprite.srv = move(srv);
	sprite.position = XMFLOAT2(100, 100);
	sprite.color = XMVectorSet(1, 1, 1, 1);
	sprite.renderCondition = true;

	sprites.push_back(sprite);
 }

void MainMenu::update(D3DX*, stack<unique_ptr<GameState>>*, FrameTimer*)
{
	for(auto & sprite : sprites)
	{
		if (sprite.name == "button_start")
		{
			sprite.position.x += 0.1f;
		}
	}
}
