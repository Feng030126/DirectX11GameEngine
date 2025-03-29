#include "D3DX.h"

bool D3DX::createD3DX(Window* wnd)
{
    ComPtr<IDXGIFactory6> dxgiFactory;
    hr = CreateDXGIFactory2(0, IID_PPV_ARGS(&dxgiFactory));
    if (FAILED(hr)) return false;

    ComPtr<IDXGIAdapter1> adapter;
    for (UINT i = 0; dxgiFactory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
    {
        hr = D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&d3dDevice));
        if (SUCCEEDED(hr)) break;
    }
    if (FAILED(hr)) return false;

    // Create Command Queue
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;

    hr = d3dDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&commandQueue));
    if (FAILED(hr)) return false;

    return true;
}

void D3DX::cleanupD3DX()
{
    commandQueue.Reset();
    d3dDevice.Reset();
}

ID3D12Device* D3DX::getDevice()
{
    return d3dDevice.Get();
}

ID3D12CommandQueue* D3DX::getCommandQueue()
{
    return commandQueue.Get();
}
