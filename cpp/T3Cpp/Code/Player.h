#pragma once
class Player
{
public:
	Player(PieceType type, IMoveHandler* moveHandler);
	void Place(int row, int column);
	PieceType GetType();
private:
	IMoveHandler* moveHandler;
	PieceType type;


};

