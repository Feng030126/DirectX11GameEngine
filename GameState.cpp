#include "GameState.h"

void GameState::render(D3DX* d3dx)
{
	////init() in each gameState should setup the description heap
	//d3dx->getCommandList()->SetDescriptorHeaps(1, descriptorHeap.GetAddressOf());

 //   // Set viewport
 //   D3D12_VIEWPORT viewport = {
 //       0.0f, 0.0f,
 //       static_cast<float>(WINDOW_WIDTH), static_cast<float>(WINDOW_HEIGHT),
 //       0.0f, 1.0f
 //   };

 //   // Begin drawing sprites
 //   spriteBatch->SetViewport(viewport);

 //   try
 //   {
 //       spriteBatch->Begin(d3dx->getCommandList());
 //   }
 //   catch (const exception& e)
 //   {
 //       cout << "error at begin" << e.what() << endl;
 //   }

 //   // Draw each sprite
 //   for (const auto& sprite : sprites) {
 //       if (sprite.renderCondition) {
 //           spriteBatch->Draw(
 //               sprite.gpuHandle,
 //               XMUINT2(sprite.texture->GetDesc().Width, sprite.texture->GetDesc().Height),
 //               sprite.position,
 //               sprite.color
 //           );
 //       }
 //   }

 //   try
 //   {
 //       spriteBatch->End();
 //   }
 //   catch (const exception& e)
 //   {
 //       cout << "error at end" << e.what() << endl;
 //   }
}
