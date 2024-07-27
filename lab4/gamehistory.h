#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H
#include "Pieces/piece.h"

namespace Chess
{
class GameHistory
{
public:
    enum MoveStatus
    {
        NO_MOVE,
        MOVE_DONE,
        TAKEN_ENEMY_PIECE
    };

private:
    char **history;
    int history_num;
    char **moves;
    int moves_num;

    GameHistory &addMove(char file_current, int rank_current, char file_target, int rank_target);

public:
    GameHistory() noexcept;
    ~GameHistory();

    GameHistory &addHistory //добавляет новый указатель на строку в массив
    (
        const Position &pos_current, const Position &pos_target,
        const Piece::Name piece_name, const MoveStatus move_status,
        const Piece::Name piece_name_new, const int move_result
    ); //for white move

    GameHistory &appendHistory //добавляет строку в конец последней строки
    (
        const Position &pos_current, const Position &pos_target,
        const Piece::Name piece_name, const MoveStatus move_status,
        const Piece::Name piece_name_new, const int move_result
    ); //for black move

    //GameHistory &deleteLastMove();

    void clearHistory();

    void printHistory(std::ostream &os) const;

    void saveToFile(std::ofstream &file) const;
};
} //namespace

#endif // GAMEHISTORY_H
