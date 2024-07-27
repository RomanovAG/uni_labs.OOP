#include "bishop.h"
#include <algorithm>

using namespace Chess;

Bishop::Bishop(const Color color)
{
    this->setColor(color);
    this->setName(this->BISHOP);
    return;
}

bool Bishop::checkMove(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (pos_target.X() - pos_current.X() != pos_target.Y() - pos_current.Y()
        && pos_target.X() + pos_target.Y() != pos_current.X() + pos_current.Y() || pos_target == pos_current)
        return false;

    if (chess_board[pos_target.X()][pos_target.Y()] != nullptr
        && (chess_board[pos_target.X()][pos_target.Y()]->getColor() == this->getColor()))
        return false;

    if (pos_target.X() - pos_current.X() == pos_target.Y() - pos_current.Y())
    {
        for (int i = std::min(pos_current.X(), pos_target.X()) + 1, j = std::min(pos_current.Y(), pos_target.Y()) + 1;
             i < std::max(pos_current.X(), pos_target.X()) && j < std::max(pos_current.Y(), pos_target.Y()); i++, j++)
            if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                return false;
    }
    else if (pos_target.X() + pos_target.Y() == pos_current.X() + pos_current.Y())
    {
        if (pos_target.Y() > pos_current.Y())
        {
            for (int i = pos_target.X() + 1, j = pos_target.Y() - 1; i < pos_current.X() && j > pos_current.Y(); i++, j--)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    return false;
        }
        else if (pos_target.Y() < pos_current.Y())
        {
            for (int i = pos_target.X() - 1, j = pos_target.Y() + 1; i > pos_current.X() && j < pos_current.Y(); i--, j++)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    return false;
        }
    }
    return true;
}

Position *Bishop::returnAvailableMoves(int *list_len, const Position &pos_current,
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

bool Bishop::checkReachability(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, 8>, 8> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (pos_target.X() - pos_current.X() != pos_target.Y() - pos_current.Y()
            && pos_target.X() + pos_target.Y() != pos_current.X() + pos_current.Y() || pos_target == pos_current)
        return false;

    if (pos_target.X() - pos_current.X() == pos_target.Y() - pos_current.Y())
    {
        for (int i = std::min(pos_current.X(), pos_target.X()) + 1, j = std::min(pos_current.Y(), pos_target.Y()) + 1;
             i < std::max(pos_current.X(), pos_target.X()) && j < std::max(pos_current.Y(), pos_target.Y()); i++, j++)
            if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                return false;
    }
    else if (pos_target.X() + pos_target.Y() == pos_current.X() + pos_current.Y())
    {
        if (pos_target.Y() > pos_current.Y())
        {
            for (int i = pos_target.X() + 1, j = pos_target.Y() - 1; i < pos_current.X() && j > pos_current.Y(); i++, j--)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    return false;
        }
        else if (pos_target.Y() < pos_current.Y())
        {
            for (int i = pos_target.X() - 1, j = pos_target.Y() + 1; i > pos_current.X() && j < pos_current.Y(); i--, j++)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    return false;
        }
    }
    return true;
}
