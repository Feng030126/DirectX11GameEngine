#include "SpriteRenderer.h"

//static
//void SpriteRenderer::initializeDescriptorHeap(int textureCount, ComPtr<ID3D12Device> device, ComPtr<ID3D12DescriptorHeap> sceneHeap)
//{
//	D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
//	srvHeapDesc.NumDescriptors = textureCount;
//	srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
//	srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
//
//	device->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&sceneHeap));
//}