#pragma once
class Board
{
public:
	Board();
	void Place(PieceType type, int row, int column);
private:
	PieceType theBoard[3][3];
	bool IsOccupied(int row, int column);
};

