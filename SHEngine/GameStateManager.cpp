#include "GameStateManager.h"
#include <iostream>

GameStateManager::GameStateManager(){
	platform = new Platform("Tank");
}

GameStateManager::~GameStateManager(){

}

void GameStateManager::GameLoop(){
	while (true){
		try{
			if (states.size() == 0){
				if(log.esp == false)
					log.Error("GSManager", "Done");
				else
					log.Error("GSManager", "Baboso");
				throw std::exception("Error");
			}
			auto state = states.top()->value;
			platform->CheckEvent(state, &GameState::Input);
			state->Update();
			state->Draw();

		}
		catch (...){
			if (log.esp == true)
				log.Error("GSManager", "Error critico");
			else
				log.Error("GSManager", "Critical error");
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state){
	state->Init(platform, this);
	states.push_front(state);
}

void GameStateManager::RealaseState(){
	auto state = states.top()->value;
	state->Close();
	states.pop();
}