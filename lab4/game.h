/*
 * Encoding: windows-1251 / CP1251
 */
#ifndef GAME_H
#define GAME_H

#include "Pieces/myarray.h"

#include "Pieces/king.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
#include "Pieces/knight.h"
#include "Pieces/bishop.h"
#include "Pieces/pawn.h"

#include "player.h"
#include "clock.h"
#include "gamehistory.h"

namespace Chess
{
class Game
{
public:
    enum GameStatus
    {
        NO_GAME,  //игры нет
        GAME_ON,  //игра идёт
        GAME_OVER //игра завершена
    };

    enum CurrentGameStatus //состояние партии
    {
        NOTHING,
        CHECK,     //шах
        MATE,      //мат
        STALE_MATE //пат
    };

private:
    std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> chess_board;
    Player player_white, player_black;
    Clock clock;
    GameHistory hisory;

    Piece::Color active_player_color;

    GameStatus game_status;
    CurrentGameStatus current_game_status;

    void setupBoard();
    void resetBoard();

    bool checkMoveForPiece(const char file_current, const int rank_current, const char file_target, const int rank_target) const;
    bool checkMoveForPiece(const Position &pos_current, const Position &pos_target) const;

    GameHistory::MoveStatus movePiece(const int x1, const int y1, const int x2, const int y2);
    GameHistory::MoveStatus movePiece(const Position &pos_current, const Position &pos_target);

    bool isCheck(const Piece::Color color) const;
    bool isMate(const Piece::Color color) const;

public:
    Game();
    ~Game();

    void setPlayersNames(const char *player_white_name, const char *player_black_name);
    const char *getPlayerName(const Piece::Color player_color) const noexcept;
    Piece::Color getActivePlayerColor() const noexcept;

    void printBoard(std::ostream &os) const;
    void printBoardLegacy(std::ostream &os) const;

    void startGame();

    GameStatus getGameStatus() const noexcept;
    CurrentGameStatus getCurrentGameStatus() const noexcept;

    //file = column (a..h), rank = row (1..8)
    bool makeMove(const char file_current, const int rank_current, const char file_target, const int rank_target);
    bool makeMove(const int x1, const int y1, const int x2, const int y2);
    bool makeMove(const Position &pos_current, const Position &pos_target);

    void addTimeToPreviousPlayer(const long long time_sec);

    void printHistory(std::ostream &os) const;

    void saveGame(std::ofstream &file) const;

    void loadGame(std::ofstream &file) const;
};
} //namespace

#endif // GAME_H
