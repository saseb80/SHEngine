#pragma once
#include "Vector2.h"
class GameObject
{
public:
	GameObject(){}
	GameObject(float x, float y);
	GameObject(Vector2 pos);
	~GameObject();

	void Position(Vector2 position);
	Vector2 Position();
	Vector2 GetPosition();
	Vector2 sum(float x, float y);
	void setPos(Vector2 position);
	void Translate(Vector2 vec);

private:
	Vector2 pos;
	void Init();
	void Draw();
	void Update();
};