#include "Window.h"

void Window::createWnd()
{
	ZeroMemory(&window_class, sizeof(WNDCLASS));

	window_class.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	window_class.hInstance = GetModuleHandle(NULL);
	window_class.lpfnWndProc = WndProc;
	window_class.lpszClassName = L"Window";
	window_class.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&window_class);

	handle_window = CreateWindowEx(
		0, window_class.lpszClassName, L"Window", WS_OVERLAPPEDWINDOW, 0, 0, scr_width, scr_height, NULL, NULL, GetModuleHandle(NULL), NULL
	);

	ShowWindow(handle_window, SW_SHOW);
}

bool Window::wndIsRunning()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

void Window::cleanupWnd()
{
	UnregisterClass(window_class.lpszClassName, GetModuleHandle(NULL));
}

LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

HWND Window::getHandle()
{
	return handle_window;
}

int Window::getScrWidth()
{
	return scr_width;
}

int Window::getScrHeight()
{
	return scr_height;
}
