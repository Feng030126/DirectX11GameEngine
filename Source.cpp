#include "D3DX.h"

int main() {
	
	Window* window = new Window();
	D3DX* d3dx = new D3DX();

	window->createWnd();

	d3dx->createD3DX(window);

	while(window->wndIsRunning())
	{
		// Do stuff
	}

	d3dx->cleanupD3DX();
	window->cleanupWnd();

	delete window;

	return 0;
}