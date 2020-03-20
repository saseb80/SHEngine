#pragma once
#include <math.h>

class Vector2
{
private:
	//Vector2* f = new Vector2();
	//Vector2* l = new Vector2();;
public:
	float x;
	float y;
	Vector2() {}
	Vector2(float x, float y);
	Vector2 normalize(Vector2 v);
	Vector2 sub(Vector2 _f, Vector2 _l);
	Vector2 add(Vector2 _f, Vector2 _l);
	Vector2 mult(Vector2 v, int n);
	Vector2 limit(Vector2 v, int n);
	float Mag();
	float GetPosX();
	float GetPosY();
	~Vector2() {}
};