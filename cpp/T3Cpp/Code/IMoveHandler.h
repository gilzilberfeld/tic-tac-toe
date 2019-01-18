#pragma once
class Player;
class IMoveHandler
{
public:
	virtual void Move (PieceType type, int row, int column) = 0;
};

