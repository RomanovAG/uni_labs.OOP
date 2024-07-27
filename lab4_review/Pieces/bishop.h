#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

namespace Chess
{
class Bishop : public Piece
{
public:
    Bishop(const Color color);

    bool checkMove(const Position &pos_current, const Position &pos_target,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
    Position *returnAvailableMoves(int *list_len, const Position &pos_current,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
    bool checkReachability(const Position &pos_current, const Position &pos_target,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
};
} //namespace

#endif // BISHOP_H
