#pragma once
#define WIN64_LEAN_AND_MEAN

#include "Input.h"

using namespace std;

class Window
{
protected:
	HWND handle_window;
	WNDCLASS window_class;
	const static int scr_width = WINDOW_WIDTH;
	const static int scr_height = WINDOW_HEIGHT;

public:
	void createWnd();
	bool wndIsRunning();
	void cleanupWnd();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	HWND getHandle();
	int getScrWidth();
	int getScrHeight();
};

