#include "GameState.h"

void GameState::render(D3DX* d3dx)
{
	d3dx->getContext()->ClearRenderTargetView(
		d3dx->getRenderTargetView(),
		Colors::Black
	);

	ID3D11RenderTargetView* renderTargetView = d3dx->getRenderTargetView();

	d3dx->getContext()->OMSetRenderTargets(1, &renderTargetView, nullptr);

	spriteBatch->Begin();

	for (auto& go : gameObjects)
	{
		if (!go->getShouldRender())
		{
			continue;
		}

		spriteBatch->Draw(
			go->getTexture(),
			go->getPosition(),
			nullptr,
			go->getColor(), 
			go->getRotation(), 
			go->getOrigin(), 
			go->getScale(),
			go->getSpriteEffects(), 
			go->getLayerDepth()
		);
	}

	spriteBatch->End();
	HRESULT hr = d3dx->getSwapChain()->Present(0, 0);

	renderTargetView->Release();
}

void GameState::cleanup()
{
	cout << "Cleaning up game state" << endl;

	//Just clear the list, and for individual pointers, it will be deleted by child
	gameObjects.clear();
}
