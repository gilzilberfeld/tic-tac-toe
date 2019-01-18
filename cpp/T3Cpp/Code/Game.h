#pragma once
class Game : public IMoveHandler
{
public:
	Game();
	Player* GetPlayerX();
	Player* GetPlayerO();
	Player* GetNextPlayer();
	bool IsOver();
	virtual void Move(PieceType type, int row, int column);
	bool PlayingAgain(PieceType type);
	virtual Player* GetCurrentPlayer();
private:
	Board board;
	Player* nextPlayer;
	Player* playerX;
	Player* playerO;
};

