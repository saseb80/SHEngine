#include "Game.h"
#include<iostream>
#include <sstream> 

ListaT<int> extractIntegerWords(std::string str)
{
	ListaT<int> Results;
	std::stringstream ss;

	/* Storing the whole string into string stream */
	ss << str;

	/* Running loop till the end of the stream */
	std::string temp;
	int found;
	while (!ss.eof())
	{

		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */
		if (std::stringstream(temp) >> found)
			Results.push_back(found);
	}
	return Results;
}

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init(Platform* platform, GameStateManager* manager)
{
	this->platform = platform;
	this->manager = manager;
	log.Debug("Game" ,"Game Init");
}

void Game::Draw()
{
	log.Debug("Game","Game Draw");
	platform->RenderClear();
	platform->RenderPresent();
}

bool Game::Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY)
{
	if (!(keyUps->size == 0))
	{
		for (int i = 0; i < keyUps->size; i++)
		{
			int num = keyUps->get_at(i)->value;
			if (num == 27)
			{
				exit(1);
			}
		}
	}

	if (!(keyDowns->size == 0))
	{
		for (int i = 0; i < keyDowns->size; i++)
		{
			int num = keyDowns->get_at(i)->value;
		}
	}

	log.Debug("Game", "Game Input");
	return false;
}

void Game::Update()
{
	log.Debug("Game", "Game Update");
}

void Game::Close()
{
	log.ImprimirConsola("Close Init");
}