#pragma once

#include "Window.h"
#include <SpriteBatch.h>
#include <WICTextureLoader.h>
#include <d3d11.h>
#include <dxgi1_6.h>
#include <wrl.h>

using namespace Microsoft::WRL;

class D3DX
{
protected:
//	bool isWindowed = false;
	ComPtr<ID3D11Device> device;
	ComPtr<ID3D11DeviceContext> context;
	ComPtr<IDXGISwapChain> swapChain;
	ComPtr<ID3D11RenderTargetView> renderTargetView;
	D3D11_VIEWPORT viewport;
	HRESULT hr;
//
public:
	bool createD3DX(Window* wnd);
	void cleanupD3DX();
	ID3D11Device* getDevice();
	ID3D11DeviceContext* getContext();
	IDXGISwapChain* getSwapChain();
	ID3D11RenderTargetView* getRenderTargetView();
};

