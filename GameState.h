#pragma once
#include "GameObject.h"
#include "SpriteRenderer.h"
#include <stack>
#include <vector>

struct Sprite
{
	//ComPtr<ID3D12Resource> texture;
	XMFLOAT2 position;
	XMVECTOR color;
	bool renderCondition;
	//D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle;
};

/// <summary>
/// The base game state, inherit this to create new "scene"
/// </summary>
class GameState
{
public:
	virtual void init(D3DX*, FrameTimer*) = 0;
	virtual void update(D3DX*, stack<unique_ptr<GameState>>*, FrameTimer*) = 0;

	//shared among gameState
	void render(D3DX*);

protected:
	//ComPtr<ID3D12DescriptorHeap> descriptorHeap;
	vector<Sprite> sprites;
	unique_ptr<SpriteBatch> spriteBatch;
};

