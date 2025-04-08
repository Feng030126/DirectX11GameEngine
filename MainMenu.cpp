#include "MainMenu.h"

void MainMenu::init(D3DX* d3dx, FrameTimer* frameTimer)
{
	//// Reset descriptor heap
	//descriptorHeap.Reset();

	////Preparing 
	//D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
	//srvHeapDesc.NumDescriptors = 1;
	//srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	//srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

	//d3dx->getDevice()->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&descriptorHeap));

	//// Create upload batch
	//ResourceUploadBatch uploadBatch(d3dx->getDevice());
	//uploadBatch.Begin();

	//RenderTargetState rtState(DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_D32_FLOAT);

	//SpriteBatchPipelineStateDescription pd(rtState);

	//spriteBatch = make_unique<SpriteBatch>(d3dx->getDevice(), uploadBatch, pd);

	//// Create sprite
	//Sprite startButton;
	//startButton.position = XMFLOAT2(100.0f, 100.0f); // example
	//startButton.color = XMVECTOR(XMVectorSet(1, 1, 1, 1));
	//startButton.renderCondition = true; 

	//CreateWICTextureFromFile(
	//	d3dx->getDevice(),
	//	uploadBatch,
	//	L"assets/start_game.png",
	//	startButton.texture.GetAddressOf(),
	//	true
	//);

	//// Finish upload
	//auto uploadDone = uploadBatch.End(d3dx->getCommandQueue());
	//uploadDone.wait();

	//int descriptorIndex = 0;
	//int descriptorSize = d3dx->getDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

	//D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
	//srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
	//srvDesc.Format = startButton.texture->GetDesc().Format;
	//srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
	//srvDesc.Texture2D.MipLevels = 1;

	//D3D12_CPU_DESCRIPTOR_HANDLE handle = descriptorHeap->GetCPUDescriptorHandleForHeapStart();
	//handle.ptr += descriptorIndex * descriptorSize;

	//d3dx->getDevice()->CreateShaderResourceView(startButton.texture.Get(), &srvDesc, handle);

	//startButton.gpuHandle = descriptorHeap->GetGPUDescriptorHandleForHeapStart();
	//startButton.gpuHandle.ptr += descriptorIndex * descriptorSize;

	//// Add to sprite list
	//sprites.push_back(startButton);
}

void MainMenu::update(D3DX*, stack<unique_ptr<GameState>>*, FrameTimer*)
{
}
