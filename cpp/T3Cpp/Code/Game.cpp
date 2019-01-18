#include "..\pch.h"
#include "PlayerType.h"
#include "IllegalMove.h"
#include "IMoveHandler.h"
#include "Player.h"
#include "Board.h"
#include "Game.h"

Game::Game()
{
	playerX = new Player(X, (IMoveHandler*) this);
	playerO = new Player(O, (IMoveHandler*) this);
	nextPlayer = playerX;
}

bool Game::IsOver()
{
	return false;
}

Player * Game::GetPlayerX()
{
	return playerX;
}

Player * Game::GetPlayerO()
{
	return playerO;
}

Player * Game::GetNextPlayer()
{
	return nextPlayer;
}

void Game::Move(PieceType type, int row, int column)
{
	if (PlayingAgain(type))
		throw IllegalMove();
	board.Place(type, row, column);
	nextPlayer = playerO;
}

bool Game::PlayingAgain(PieceType type)
{
	return type != GetNextPlayer()->GetType();
}

Player * Game::GetCurrentPlayer()
{
	return GetNextPlayer();
}
