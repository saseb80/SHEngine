#include "GameObject.h"

GameObject::GameObject(float x, float y) {
	pos.x = x;	
	pos.y = y;	
}

GameObject::GameObject(Vector2 pos) {
	pos = pos;
}

GameObject::~GameObject() {
}

void GameObject::Position(Vector2 position) {
	pos = position;
}


Vector2 GameObject::Position() {
	return pos;
}

Vector2 GameObject::GetPosition() {
	return pos;
}

Vector2 GameObject::sum(float x, float y) {
	pos.x += x;
	pos.y += y;
	return pos;
}

void GameObject::setPos(Vector2 position) {
	pos = position;
}


void GameObject::Translate(Vector2 vec) {
	pos.add(pos, vec);
}


void GameObject::Update() {

}

void GameObject::Draw() {
}