#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

namespace Chess
{
class Knight : public Piece
{
public:
    Knight(const Color color);

    bool checkMove(const Position &pos_current, const Position &pos_target,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
    Position *returnAvailableMoves(int *list_len, const Position &pos_current,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
    bool checkReachability(const Position &pos_current, const Position &pos_target,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;

//    bool checkMove(const Position &pos_current, const Position &pos_target,
//        const myarray::array<myarray::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
//    Position *returnAvailableMoves(int *list_len, const Position &pos_current,
//        const myarray::array<myarray::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
//    bool checkReachability(const Position &pos_current, const Position &pos_target,
//        const myarray::array<myarray::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const override;
};
} //namespace

#endif // KNIGHT_H
