#include "D3DX.h"

int main() {
	
	Window* window = new Window();
	D3DX* d3dx = new D3DX();

	window->createWnd();

	d3dx->createD3DX(window);

	Input::initialize(window->getHandle());

	while(window->wndIsRunning())
	{
		//TODO: Seems to have some issues with mouse position not limited and increase infinitely
		XMFLOAT3 mousePos = Input::getMousePos();
		std::cout << "Mouse Position: X=" << mousePos.x << ", Y=" << mousePos.y << '\n';
	}

	d3dx->cleanupD3DX();
	window->cleanupWnd();

	delete window;

	return 0;
}