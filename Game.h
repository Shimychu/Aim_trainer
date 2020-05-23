#pragma once

enum GameState
{
	GAME_MENU = 0,
	GAME_1 = 1,
};

static class Game
{
public:
	Game();

	~Game();

	GameState getGameState();

private:

	GameState currentGameState;
};


