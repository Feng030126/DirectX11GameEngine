#include "Window.h"

int main() {
	
	Window* window = new Window();

	window->createWnd();

	while(window->wndIsRunning())
	{
		// Do stuff
	}

	window->cleanupWnd();

	return 0;
}