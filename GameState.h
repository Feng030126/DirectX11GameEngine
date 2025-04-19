#pragma once
#include "Button.h"
#include "SpriteRenderer.h"
#include <stack>
#include <vector>

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
	//ComPtr<ID3D11DescriptorHeap> descriptorHeap;
	vector<GameObject> gameObjects;
	unique_ptr<SpriteBatch> spriteBatch;
};

