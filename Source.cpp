#include "MainMenu.h"
#include <roapi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "runtimeobject.lib")

int main()
{
#if (_WIN32_WINNT >= 0x0A00 /*_WIN32_WINNT_WIN10*/)
	Wrappers::RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
	if (FAILED(initialize))
		return -1;
#else
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr))
		return -1;
#endif

	/*unique_ptr<Window> window = make_unique<Window>();
	unique_ptr<D3DX> d3dx = make_unique<D3DX>();
	unique_ptr<FrameTimer> frameTimer = make_unique<FrameTimer>();
	unique_ptr<stack<unique_ptr<GameState>>> gsm = make_unique<stack<unique_ptr<GameState>>>();*/

	Window wnd;
	D3DX d3dx;
	FrameTimer frameTimer;
	stack<unique_ptr<GameState>> gsm;

	wnd.createWnd();
	d3dx.createD3DX(wnd);
	Input::initialize(wnd.getHandle());

	unique_ptr<MainMenu> mainMenu = make_unique<MainMenu>();

	gsm.push(move(mainMenu));
	gsm.top()->init(d3dx, frameTimer);

	while(wnd.wndIsRunning())
	{
		gsm.top()->render(d3dx);
		gsm.top()->update(d3dx, gsm, frameTimer);
	}

	//Cleanup leftover game states
	for (int i = 0; i < gsm.size(); i++)
	{
		gsm.top()->cleanup();
		gsm.pop();
	}

	d3dx.cleanupD3DX();
	wnd.cleanupWnd();

	return 0;
}