#include "queen.h"

using namespace Chess;

Queen::Queen(const Color color)
{
    this->setColor(color);
    this->setName(this->QUEEN);
    return;
}

bool Queen::checkMove(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, BOARD_SIZE>, BOARD_SIZE> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (pos_target.X() != pos_current.X() && pos_target.Y() != pos_current.Y()
            && pos_target.X() - pos_current.X() != pos_target.Y() - pos_current.Y()
            && pos_target.X() + pos_target.Y() != pos_current.X() + pos_current.Y() || pos_target == pos_current)
        return false;

    if (chess_board[pos_target.X()][pos_target.Y()] != nullptr
        && (/*chess_board[pos_target.X()][pos_target.Y()]->getName() == this->KING
            ||*/ chess_board[pos_target.X()][pos_target.Y()]->getColor() == this->getColor()))
        return false;

    //rook condition
    if (pos_current.Y() == pos_target.Y())
    {
        for (int i = std::min(pos_current.X(), pos_target.X()) + 1; i < std::max(pos_current.X(), pos_target.X()); i++)
            if (chess_board[i][pos_current.Y()] != nullptr && chess_board[i][pos_current.Y()] != this)
                //&& (/*chess_board[i][pos_current.Y()]->getName() == this->KING ||*/ chess_board[i][pos_current.Y()]->getColor() == this->getColor()))
                return false;
    }
    else if (pos_current.X() == pos_target.X())
    {
        for (int i = std::min(pos_current.Y(), pos_target.Y()) + 1; i < std::max(pos_current.Y(), pos_target.Y()); i++)
            if (chess_board[pos_current.X()][i] != nullptr && chess_board[pos_current.X()][i] != this)
                //&& (/*chess_board[i][pos_current.Y()]->getName() == this->KING ||*/ chess_board[i][pos_current.Y()]->getColor() == this->getColor()))
                return false;
    }
    //bishop condition
    else if (pos_target.X() - pos_current.X() == pos_target.Y() - pos_current.Y())
    {
        for (int i = std::min(pos_current.X(), pos_target.X()) + 1, j = std::min(pos_current.Y(), pos_target.Y()) + 1;
             i < std::max(pos_current.X(), pos_target.X()) && j < std::max(pos_current.Y(), pos_target.Y()); i++, j++)
            if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                //&& (/*chess_board[i][j]->getName() == this->KING ||*/ chess_board[i][j]->getColor() == this->getColor()))
                return false;
    }
    else if (pos_target.X() + pos_target.Y() == pos_current.X() + pos_current.Y())
    {
        if (pos_target.Y() > pos_current.Y())
        {
            for (int i = pos_target.X() + 1, j = pos_target.Y() - 1; i < pos_current.X() && j > pos_current.Y(); i++, j--)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    //&& (/*chess_board[i][j]->getName() == this->KING ||*/ chess_board[i][j]->getColor() == this->getColor()))
                    return false;
        }
        else if (pos_target.Y() < pos_current.Y())
        {
            for (int i = pos_target.X() - 1, j = pos_target.Y() + 1; i > pos_current.X() && j < pos_current.Y(); i--, j++)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    //&& (/*chess_board[i][j]->getName() == this->KING ||*/ chess_board[i][j]->getColor() == this->getColor()))
                    return false;
        }
    }
    return true;
}

Position *Queen::returnAvailableMoves(int *list_len, const Position &pos_current,
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

bool Queen::checkReachability(const Position &pos_current, const Position &pos_target,
    const std::array<std::array<Piece *, 8>, 8> &chess_board) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        return false;

    if (pos_target.X() != pos_current.X() && pos_target.Y() != pos_current.Y()
            && pos_target.X() - pos_current.X() != pos_target.Y() - pos_current.Y()
            && pos_target.X() + pos_target.Y() != pos_current.X() + pos_current.Y() || pos_target == pos_current)
        return false;

    if (pos_current.Y() == pos_target.Y())
    {
        for (int i = std::min(pos_current.X(), pos_target.X()) + 1; i < std::max(pos_current.X(), pos_target.X()); i++)
            if (chess_board[i][pos_current.Y()] != nullptr && chess_board[i][pos_current.Y()] != this)
                //&& (/*chess_board[i][pos_current.Y()]->getName() == this->KING ||*/ chess_board[i][pos_current.Y()]->getColor() == this->getColor()))
                return false;
    }
    else if (pos_current.X() == pos_target.X())
    {
        for (int i = std::min(pos_current.Y(), pos_target.Y()) + 1; i < std::max(pos_current.Y(), pos_target.Y()); i++)
            if (chess_board[pos_current.X()][i] != nullptr && chess_board[pos_current.X()][i] != this)
                //&& (/*chess_board[i][pos_current.Y()]->getName() == this->KING ||*/ chess_board[i][pos_current.Y()]->getColor() == this->getColor()))
                return false;
    }
    //bishop condition
    else if (pos_target.X() - pos_current.X() == pos_target.Y() - pos_current.Y())
    {
        for (int i = std::min(pos_current.X(), pos_target.X()) + 1, j = std::min(pos_current.Y(), pos_target.Y()) + 1;
             i < std::max(pos_current.X(), pos_target.X()) && j < std::max(pos_current.Y(), pos_target.Y()); i++, j++)
            if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                //&& (/*chess_board[i][j]->getName() == this->KING ||*/ chess_board[i][j]->getColor() == this->getColor()))
                return false;
    }
    else if (pos_target.X() + pos_target.Y() == pos_current.X() + pos_current.Y())
    {
        if (pos_target.Y() > pos_current.Y())
        {
            for (int i = pos_target.X() + 1, j = pos_target.Y() - 1; i < pos_current.X() && j > pos_current.Y(); i++, j--)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    //&& (/*chess_board[i][j]->getName() == this->KING ||*/ chess_board[i][j]->getColor() == this->getColor()))
                    return false;
        }
        else if (pos_target.Y() < pos_current.Y())
        {
            for (int i = pos_target.X() - 1, j = pos_target.Y() + 1; i > pos_current.X() && j < pos_current.Y(); i--, j++)
                if (chess_board[i][j] != nullptr && chess_board[i][j] != this)
                    //&& (/*chess_board[i][j]->getName() == this->KING ||*/ chess_board[i][j]->getColor() == this->getColor()))
                    return false;
        }
    }
    return true;
}
