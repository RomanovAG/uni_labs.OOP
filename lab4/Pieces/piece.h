/*
 * Base abstract class
 */
#ifndef PIECE_H
#define PIECE_H

#define BOARD_SIZE 8

//#define array MyArray //--\
                          |--> закомментируйте define и раскомментируйте include, чтобы использовать стандартный контейнер из STL
#include <array>    //--/

#include "myarray.h"
#include "position.h"

namespace Chess
{
class Piece
{
public:
    enum Color
    {
        WHITE = 1,
        BLACK
    };

    enum Name
    {
        KING,   //K | король
        QUEEN,  //Q | ферзь
        ROOK,   //R | ладья
        KNIGHT, //N | конь
        BISHOP, //B | слон
        PAWN    //P | пешка
    };

private:
    Color color;
    Name name;

public:
    virtual ~Piece();

    void setColor(const Color color);
    void setName(const Name name);

    Color getColor() const noexcept;
    Name getName() const noexcept;

    virtual bool checkMove(const Position &pos_current, const Position &pos_target,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const = 0;
    virtual Position *returnAvailableMoves(int *list_len, const Position &pos_current,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const = 0; //array of positions
    virtual bool checkReachability(const Position &pos_current, const Position &pos_target,
        const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const = 0;

//    //for my array
//    virtual bool checkMove(const Position &pos_current, const Position &pos_target,
//        const myarray::array<myarray::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const = 0;
//    virtual Position *returnAvailableMoves(int *list_len, const Position &pos_current,
//        const myarray::array<myarray::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const = 0; //array of positions
//    virtual bool checkReachability(const Position &pos_current, const Position &pos_target,
//        const myarray::array<myarray::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const = 0;
};
} //namespace

#endif // PIECE_H
