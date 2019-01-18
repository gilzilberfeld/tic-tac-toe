#include "..\pch.h"
#include "IllegalMove.h"
#include "PlayerType.h"
#include "IMoveHandler.h"
#include "Player.h"
#include "Board.h"

Player::Player(PieceType type, IMoveHandler* moveHandler)
{
	this->type = type;
	this->moveHandler = moveHandler;
}

void Player::Place(int row, int column)
{
	moveHandler->Move(type, row, column);
}

PieceType Player::GetType()
{
	return type;
}
