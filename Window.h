#pragma once
#define WIN64_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>

using namespace std;

class Window
{
protected:
	HWND handle_window;
	WNDCLASS window_class;
	const static int scr_width = 800;
	const static int scr_height = 600;

public:
	void createWnd();
	bool wndIsRunning();
	void cleanupWnd();
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	HWND getHandle();
	int getScrWidth();
	int getScrHeight();
};

