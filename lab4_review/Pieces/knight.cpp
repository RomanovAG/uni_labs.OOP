#include "knight.h"

using namespace Chess;

Knight::Knight(const Color color)
{
    this->setColor(color);
    this->setName(this->KNIGHT);
    return;
}

bool Knight::checkMove(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (chess_board[pos_target.X()][pos_target.Y()] != nullptr
        && (chess_board[pos_target.X()][pos_target.Y()]->getColor() == this->getColor()))
        return false;

    //for knight there are maximum 8 available moves
    if (pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() + 2
        || pos_target.X() == pos_current.X() + 2 && pos_target.Y() == pos_current.Y() + 1
        || pos_target.X() == pos_current.X() + 2 && pos_target.Y() == pos_current.Y() - 1
        || pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() - 2
        || pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() - 2
        || pos_target.X() == pos_current.X() - 2 && pos_target.Y() == pos_current.Y() - 1
        || pos_target.X() == pos_current.X() - 2 && pos_target.Y() == pos_current.Y() + 1
        || pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() + 2)
        return true;

    return false;
}

Position *Knight::returnAvailableMoves(int *list_len, const Position &pos_current,
    const std::array<std::array<Piece *, 8>, 8> &chess_board) const
{
    Position *pos_list = nullptr;
    *list_len = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (this->checkMove(pos_current, Position(i, j), chess_board) == true)
            {
                (*list_len)++;
                Position *new_pos_list = new Position [*list_len];
                for (int x = 0; x < (*list_len) - 1; x++)
                    new_pos_list[x] = pos_list[x];
                delete [] pos_list;
                pos_list = new_pos_list;
                pos_list[(*list_len) - 1] = Position(i, j);
            }
    return pos_list;
}

bool Knight::checkReachability(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, 8>, 8> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() + 2
        || pos_target.X() == pos_current.X() + 2 && pos_target.Y() == pos_current.Y() + 1
        || pos_target.X() == pos_current.X() + 2 && pos_target.Y() == pos_current.Y() - 1
        || pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() - 2
        || pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() - 2
        || pos_target.X() == pos_current.X() - 2 && pos_target.Y() == pos_current.Y() - 1
        || pos_target.X() == pos_current.X() - 2 && pos_target.Y() == pos_current.Y() + 1
        || pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() + 2)
        return true;

    return false;
}