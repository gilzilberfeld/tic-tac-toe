#include "..\pch.h"

#include "..\Code\PlayerType.h"
#include "..\Code\IllegalMove.h"
#include "..\Code\IMoveHandler.h"
#include "..\Code\Player.h"
#include "..\Code\Board.h"
#include "..\Code\Game.h"


TEST(GameTests, gameIsNotOver_inTheBeginning)
{
	Game game;
	EXPECT_FALSE(game.IsOver());
}

TEST(GameTests, aGameHasTwoPlayers)
{
	Game game;
	Player* x = game.GetPlayerX();
	Player* o = game.GetPlayerO();
	EXPECT_NE(x, nullptr);
	EXPECT_NE(o, nullptr);
}

TEST(GameTests, firstPlayerIsX)
{
	Game game;
	Player* playerX = game.GetPlayerX();
	Player* nextPlayer = game.GetNextPlayer();
	EXPECT_EQ(playerX->GetType(), nextPlayer->GetType());
}

TEST(GameTests, whenPlayerXMarksAnEmptySpace_thenItIsPlayerOTurn)
{
	Game game;
	Player* playerX = game.GetPlayerX();
	Player* playerO = game.GetPlayerO();
	playerX->Place(2, 2);
	Player* nextPlayer = game.GetNextPlayer();
	EXPECT_EQ(playerO->GetType(), nextPlayer->GetType());
}

TEST(GameTests, whenPlayerOMarksAnEmptySpace_thenItIsPlayerXTurn)
{
	Game game;
	Player* playerX = game.GetPlayerX();
	Player* playerO = game.GetPlayerO();
	playerX->Place(2, 2);
	playerO->Place(1, 0);
	Player* nextPlayer = game.GetNextPlayer();
	EXPECT_EQ(playerO->GetType(), nextPlayer->GetType());
}

TEST(GameTests, aPlayerCannotMarkAnOccupiedSpace )
{
	Game game;
	Player* playerX = game.GetPlayerX();
	Player* playerO = game.GetPlayerO();
	playerX->Place(2, 2);
	EXPECT_THROW(playerX->Place(2, 2), IllegalMove);
}

TEST(GameTests, aPlayerCannotPlaceTwiceInSequence)
{
	Game game;
	Player* playerX = game.GetPlayerX();
	playerX->Place(2, 2);
	EXPECT_THROW(playerX->Place(1, 0), IllegalMove);
}

#define ndef
#ifndef ndef

TEST(GameTests, aGameIsWon_whenARowOfThreeOfTheSameMark) {}
TEST(GameTests, aGameIsWon_whenAColumnOfThreeOfTheSameMark) {}
TEST(GameTests, aGameIsWon_whenADiagonalOfThreeOfTheSameMark) {}
TEST(GameTests, whenAGameIsTied_ThereIsNoWinner) {}
TEST(GameTests, whenAGameIsTied_allSpacesAreOccupied) {}
TEST(GameTests, whenAGameIsWon_thenThereIsOneWinner) {}
TEST(GameTests, whenThereIsATie_thenTheGameIsOver) {}
TEST(GameTests, whenThereIsAWinner_thenTheGameIsOver) {}

#endif