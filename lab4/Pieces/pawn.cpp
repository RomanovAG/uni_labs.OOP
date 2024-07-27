#include "pawn.h"
#include <iostream>

using namespace Chess;

Pawn::Pawn(const Color color)
{
    this->setColor(color);
    this->setName(this->PAWN);
    return;
}

bool Pawn::checkMove(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    //2 moves for white and 2 for black (taking enemy piece)
    if (this->getColor() == this->WHITE)
    {
        if (pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() + 1
            && chess_board[pos_target.X()][pos_target.Y()] != nullptr /*&& chess_board[pos_target.X()][pos_target.Y()]->getName() != this->KING*/
            && chess_board[pos_target.X()][pos_target.Y()]->getColor() != this->getColor())
            return true;
        if (pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() + 1
            && chess_board[pos_target.X()][pos_target.Y()] != nullptr /*&& chess_board[pos_target.X()][pos_target.Y()]->getName() != this->KING*/
            && chess_board[pos_target.X()][pos_target.Y()]->getColor() != this->getColor())
            return true;
    }
    else
    {
        if (pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() - 1
            && chess_board[pos_target.X()][pos_target.Y()] != nullptr /*&& chess_board[pos_target.X()][pos_target.Y()]->getName() != this->KING*/
            && chess_board[pos_target.X()][pos_target.Y()]->getColor() != this->getColor())
            return true;
        if (pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() - 1
            && chess_board[pos_target.X()][pos_target.Y()] != nullptr /*&& chess_board[pos_target.X()][pos_target.Y()]->getName() != this->KING*/
            && chess_board[pos_target.X()][pos_target.Y()]->getColor() != this->getColor())
            return true;
    }

    if (pos_target.X() != pos_current.X() || pos_target == pos_current)
        return false;

    if (chess_board[pos_target.X()][pos_target.Y()] != nullptr)
        return false;

    if (this->getColor() == this->WHITE)
    {
        if (pos_target.Y() <= pos_current.Y())
            return false;
        if (pos_current.Y() == 1)
        {
            if (pos_target.Y() > 3 || chess_board[pos_current.X()][2] != nullptr && pos_target.Y() == 3)
                return false;
        }
        else
            if (pos_target.Y() > pos_current.Y() + 1)
                return false;
    }
    else
    {
        if (pos_target.Y() >= pos_current.Y())
            return false;
        if (pos_current.Y() == 6)
        {
            if (pos_target.Y() < 4 || chess_board[pos_current.X()][5] != nullptr && pos_target.Y() == 4)
                return false;
        }
        else
            if (pos_target.Y() < pos_current.Y() - 1)
                return false;
    }
    return true;
}

Position *Pawn::returnAvailableMoves(int *list_len, const Position &pos_current,
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

bool Pawn::checkReachability(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, 8>, 8> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (this->getColor() == this->WHITE)
    {
        if (pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() + 1)
            return true;
        if (pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() + 1)
            return true;
    }
    else
    {
        if (pos_target.X() == pos_current.X() + 1 && pos_target.Y() == pos_current.Y() - 1)
            return true;
        if (pos_target.X() == pos_current.X() - 1 && pos_target.Y() == pos_current.Y() - 1)
            return true;
    }

    if (this->getColor() == this->WHITE)
    {
        if (pos_target.Y() <= pos_current.Y())
            return false;
        if (pos_current.Y() == 1)
        {
            if (pos_target.Y() > 3 || chess_board[pos_current.X()][2] != nullptr && pos_target.Y() == 3)
                return false;
        }
        else
            if (pos_target.Y() > pos_current.Y() + 1)
                return false;
    }
    else
    {
        if (pos_target.Y() >= pos_current.Y())
            return false;
        if (pos_current.Y() == 6)
        {
            if (pos_target.Y() < 4 || chess_board[pos_current.X()][5] != nullptr && pos_target.Y() == 4)
                return false;
        }
        else
            if (pos_target.Y() < pos_current.Y() - 1)
                return false;
    }
    return true;
}
