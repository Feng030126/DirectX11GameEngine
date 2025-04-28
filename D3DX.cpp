#include "D3DX.h"

bool D3DX::createD3DX(Window* wnd)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferDesc.Width = WINDOW_WIDTH;
	swapChainDesc.BufferDesc.Height = WINDOW_HEIGHT;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_STRETCHED;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = wnd->getHandle();
	swapChainDesc.Windowed = FALSE;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    hr = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&swapChainDesc,
		swapChain.GetAddressOf(),
		device.GetAddressOf(),
		nullptr,
		context.GetAddressOf()
	);

    if(FAILED(hr))
	{
		cout << "Failed to create D3D11 device and swap chain: " << hr << endl;

		if(device == nullptr)
		{
			cout << "Device is null" << endl;
		}
		
		if(context == nullptr)
		{
			cout << "Context is null" << endl;
		}

		if(swapChain == nullptr)
		{
			cout << "Swap chain is null" << endl;
		}

		return false;
	}

	ID3D11Texture2D* backBuffer;
	hr = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

	if (FAILED(hr))
	{
		cout << "Failed to get back buffer: " << hr << endl;
		return false;
	}

	hr = device->CreateRenderTargetView(backBuffer, nullptr, renderTargetView.GetAddressOf());

	if (FAILED(hr))
	{
		cout << "Failed to create render target view: " << hr << endl;
		backBuffer->Release();
		return false;
	}

	viewport.Width = static_cast<FLOAT>(WINDOW_WIDTH);
	viewport.Height = static_cast<FLOAT>(WINDOW_HEIGHT);
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;

	context->RSSetViewports(1, &viewport);

	return true;
}

void D3DX::cleanupD3DX()
{
	device.Reset();
	context.Reset();
	swapChain.Reset();
}

ID3D11Device* D3DX::getDevice()
{
	return device.Get();
}

ID3D11DeviceContext* D3DX::getContext()
{
	return context.Get();
}

IDXGISwapChain* D3DX::getSwapChain()
{
	return swapChain.Get();
}

ID3D11RenderTargetView* D3DX::getRenderTargetView()
{
	return renderTargetView.Get();
}
