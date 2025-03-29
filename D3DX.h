#pragma once

#include "Window.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

using namespace Microsoft::WRL;

class D3DX
{
protected:
	bool isWindowed = false;
	ComPtr<ID3D12Device> d3dDevice;
	ComPtr<ID3D12CommandQueue> commandQueue;
	HRESULT hr;

public:
	bool createD3DX(Window* wnd);
	void cleanupD3DX();
	ID3D12Device* getDevice();
	ID3D12CommandQueue* getCommandQueue();
};

