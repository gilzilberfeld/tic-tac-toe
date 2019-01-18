#include "../pch.h"
#include "IllegalMove.h"
#include "PlayerType.h"
#include "Board.h"

Board::Board()
{
	for (int row = 0; row < 3; row++)
		for (int column = 0; column < 3; column++)
		{
			theBoard[row][column] = None;
		}
}

void Board::Place(PieceType type, int row, int column)
{
	if (IsOccupied(row, column))
		throw IllegalMove();
	else
		theBoard[row][column] = type;
}

bool Board::IsOccupied(int row, int column)
{
	PieceType type = theBoard[row][column];
	return type != None;
}


