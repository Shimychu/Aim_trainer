#include "Game.h"

Game::Game() 
{
	currentGameState = GAME_MENU;
}

GameState Game::getGameState()
{
	return currentGameState;
}