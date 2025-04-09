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

	for (const auto& sprite : sprites)
	{
		if (sprite->renderCondition)
		{
			spriteBatch->Draw(
				sprite->srv.Get(),
				sprite->position,
				Colors::White
			);
		}
	}

	spriteBatch->End();
	HRESULT hr = d3dx->getSwapChain()->Present(0, 0);

	renderTargetView->Release();
}
