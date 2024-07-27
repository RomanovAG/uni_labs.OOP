#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "D:\Labs\OOP\lab4\game.h"

using namespace testing;
using namespace Chess;

TEST(lab4_tests, constructor)
{
    Game game;
    ASSERT_NO_THROW(Game game);
    ASSERT_EQ(Game::NO_GAME, game.getGameStatus());
    ASSERT_NO_THROW(game.startGame());

    ASSERT_EQ(Game::GAME_ON, game.getGameStatus());
}

TEST(lab4_tests, pawn)
{
    Game game;
    game.startGame();

    ASSERT_EQ(true, game.makeMove('e', 2, 'e', 4));
    ASSERT_EQ(false, game.makeMove('e', 2, 'e', 5));
    ASSERT_EQ(false, game.makeMove('d', 2, 'e', 3));
    ASSERT_EQ(false, game.makeMove('d', 2, 'd', 1));
    ASSERT_EQ(false, game.makeMove('a', 2, 'a', 1));
}

TEST(lab4_tests, king)
{
    Game game;
    game.startGame();

    game.makeMove('e', 2, 'e', 4);
    game.makeMove('e', 7, 'e', 6);

    ASSERT_EQ(true, game.makeMove('e', 1, 'e', 2));
    ASSERT_EQ(false, game.makeMove('e', 8, 'f', 7));
}

TEST(lab4_tests, queen)
{
    Game game;
    game.startGame();

    game.makeMove('e', 2, 'e', 4);
    game.makeMove('e', 7, 'e', 6);
    ASSERT_EQ(true, game.makeMove('d', 1, 'h', 5));
    game.makeMove('e', 6, 'e', 5);
    ASSERT_EQ(true, game.makeMove('h', 5, 'h', 4));
}

TEST(lab4_tests, bishop)
{
    Game game;
    game.startGame();

    ASSERT_EQ(true, game.makeMove('e', 2, 'e', 4));
    ASSERT_EQ(true, game.makeMove('f', 7, 'f', 5));

    ASSERT_EQ(false, game.makeMove('f', 1, 'h', 3));
    ASSERT_EQ(true, game.makeMove('f', 1, 'c', 4));
}

TEST(lab4_tests, knight)
{
    Game game;
    game.startGame();

    ASSERT_EQ(true, game.makeMove('b', 1, 'a', 3));
    ASSERT_EQ(false, game.makeMove('b', 8, 'd', 7));
    ASSERT_EQ(true, game.makeMove('b', 8, 'c', 6));
}

TEST(lab4_tests, rook)
{
    Game game;
    game.startGame();

    game.makeMove('a', 2, 'a', 4);
    game.makeMove('e', 7, 'e', 6);

    ASSERT_EQ(true, game.makeMove('a', 1, 'a', 3));
    ASSERT_EQ(false, game.makeMove('a', 3, 'a', 2));
    game.makeMove('e', 6, 'e', 5);
    ASSERT_EQ(true, game.makeMove('a', 3, 'a', 2));
}

TEST(lab4_tests, check)
{
    Game game;
    game.startGame();

    ASSERT_EQ(true, game.makeMove('f', 2, 'f', 4));
    ASSERT_EQ(true, game.makeMove('e', 7, 'e', 6));
    ASSERT_EQ(true, game.makeMove('e', 1, 'f', 2));
    ASSERT_EQ(true, game.makeMove('d', 8, 'f', 6));
    ASSERT_EQ(true, game.makeMove('e', 2, 'e', 4));
    ASSERT_EQ(true, game.makeMove('f', 6, 'h', 4));

    ASSERT_EQ(Game::CHECK, game.getCurrentGameStatus());
    ASSERT_EQ(Game::GAME_ON, game.getGameStatus());
}

TEST(lab4_tests, child_mate)
{
    Game game;
    game.startGame();

    ASSERT_EQ(true, game.makeMove('e', 2, 'e', 4));
    ASSERT_EQ(true, game.makeMove('e', 7, 'e', 5));
    ASSERT_EQ(true, game.makeMove('f', 1, 'c', 4));
    ASSERT_EQ(true, game.makeMove('b', 8, 'c', 6));
    ASSERT_EQ(true, game.makeMove('d', 1, 'h', 5));
    ASSERT_EQ(true, game.makeMove('g', 8, 'f', 6));
    ASSERT_EQ(true, game.makeMove('h', 5, 'f', 7));

    ASSERT_EQ(Game::MATE, game.getCurrentGameStatus());
    ASSERT_EQ(Game::GAME_OVER, game.getGameStatus());
}
