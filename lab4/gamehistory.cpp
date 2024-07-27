#include "gamehistory.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace Chess;

GameHistory &GameHistory::addMove(char file_current, int rank_current, char file_target, int rank_target)
{
    this->moves_num++;
    char *move = new char [9];
    std::snprintf(move, 9, "%c %d %c %d\n", file_current, rank_current, file_target, rank_target);

    char **new_moves = new char *[this->moves_num];
    for (int i = 0; i < this->moves_num - 1; i++)
    {
        new_moves[i] = new char [std::strlen(this->moves[i]) + 1];
        std::strcpy(new_moves[i], this->moves[i]);
    }

    new_moves[this->moves_num - 1] = move;

    for (int i = 0; i < this->moves_num - 1; i++)
        delete [] this->moves[i];
    delete [] this->moves;

    this->moves = new_moves;

    return *this;
}

GameHistory::GameHistory() noexcept
{
    this->history = nullptr;
    this->history_num = 0;
    this->moves = nullptr;
    this->moves_num = 0;
    return;
}

GameHistory::~GameHistory()
{
    for (int i = 0; i < this->history_num; i++)
        delete [] this->history[i];
    delete [] this->history;

    for (int i = 0; i < this->moves_num; i++)
        delete [] this->moves[i];
    delete [] this->moves;

    return;
}

GameHistory &GameHistory::addHistory(const Position &pos_current, const Position &pos_target,
    const Piece::Name piece_name, const MoveStatus move_status, const Piece::Name piece_name_new,
    const int move_result)
{
    this->history_num++;
    char buff[32] = {0};

    char file_current = pos_current.X() + 'a';
    int rank_current = pos_current.Y() + 1;
    char file_target = pos_target.X() + 'a';
    int rank_target = pos_target.Y() + 1;

    this->addMove(file_current, rank_current, file_target, rank_target);

    char name = 0;
    if (piece_name == Piece::KING)
        name = 'K';
    if (piece_name == Piece::QUEEN)
        name = 'Q';
    if (piece_name == Piece::ROOK)
        name = 'R';
    if (piece_name == Piece::KNIGHT)
        name = 'N';
    if (piece_name == Piece::BISHOP)
        name = 'B';
    if (piece_name == Piece::PAWN)
        name = 'P';

    char status = 0;
    if (move_status == this->MOVE_DONE)
        status = '-';
    if (move_status == this->TAKEN_ENEMY_PIECE)
        status = 'x';

    char result = 0;
    if (move_result == 0)
        result = ' ';
    if (move_result == 1)
        result = '+';
    if (move_result == 2)
        result = '#';
    if (move_result == 3)
        result = '=';

    std::snprintf(buff, 32, "%d. %c%c%d%c%c%d%c", this->history_num, name,
        file_current, rank_current, status, file_target, rank_target, result);
    char *move = new char [std::strlen(buff) + 1];
    std::strcpy(move, buff);

    char **new_history = new char *[this->history_num];
    for (int i = 0; i < this->history_num - 1; i++)
    {
        new_history[i] = new char [std::strlen(this->history[i]) + 1];
        std::strcpy(new_history[i], this->history[i]);
    }

    new_history[this->history_num - 1] = move;

    for (int i = 0; i < this->history_num - 1; i++)
        delete [] this->history[i];
    delete [] this->history;

    this->history = new_history;
    return *this;
}

GameHistory &GameHistory::appendHistory(const Position &pos_current, const Position &pos_target, const Piece::Name piece_name, const MoveStatus move_status, const Piece::Name piece_name_new, const int move_result)
{
    char buff[32] = {0};

    char file_current = pos_current.X() + 'a';
    int rank_current = pos_current.Y() + 1;
    char file_target = pos_target.X() + 'a';
    int rank_target = pos_target.Y() + 1;

    this->addMove(file_current, rank_current, file_target, rank_target);

    char name = 0;
    if (piece_name == Piece::KING)
        name = 'K';
    else if (piece_name == Piece::QUEEN)
        name = 'Q';
    else if (piece_name == Piece::ROOK)
        name = 'R';
    else if (piece_name == Piece::KNIGHT)
        name = 'N';
    else if (piece_name == Piece::BISHOP)
        name = 'B';
    else if (piece_name == Piece::PAWN)
        name = 'P';

    char status = 0;
    if (move_status == this->MOVE_DONE)
        status = '-';
    else if (move_status == this->TAKEN_ENEMY_PIECE)
        status = 'x';

    char result = 0;
    if (move_result == 0)
        result = ' ';
    else if (move_result == 1)
        result = '+';
    else if (move_result == 2)
        result = '#';
    else if (move_result == 3)
        result = '=';

    std::snprintf(buff, 32, " %c%c%d%c%c%d%c", name,
        file_current, rank_current, status, file_target, rank_target, result);
    char *move = new char [std::strlen(buff) + 1];
    std::strcpy(move, buff);

    char *new_move = new char [std::strlen(this->history[this->history_num - 1]) + std::strlen(move) + 1];

    std::strcpy(new_move, this->history[this->history_num - 1]);
    std::strcat(new_move, move);

    delete [] move;

    delete [] this->history[this->history_num - 1];

    this->history[this->history_num - 1] = new_move;

    return *this;
}

//GameHistory &GameHistory::deleteLastMove()
//{
//    delete [] this->history[this->history_num - 1];
//    this->history_num--;

//    char **new_history = new char *[this->history_num];
//    for (int i = 0; i < this->history_num - 1; i++)
//    {
//        new_history[i] = new char [std::strlen(this->history[i]) + 1];
//        std::strcpy(new_history[i], this->history[i]);
//    }

//    for (int i = 0; i < this->history_num - 1; i++)
//        delete [] this->history[i];
//    delete [] this->history;

//    this->history = new_history;
//    return *this;
//}

//const char *GameHistory::returnAsString() const
//{
//    int length = 0;
//    for (int i = 0; i < this->number_of_moves; i++)
//        length += std::strlen(this->history[i]) + 2;
//}

void GameHistory::clearHistory()
{
    for (int i = 0; i < this->history_num; i++)
        delete [] this->history[i];
    delete [] this->history;
    this->history = nullptr;
    this->history_num = 0;
    return;
}

void GameHistory::printHistory(std::ostream &os) const
{
    for (int i = 0; i < this->history_num; i++)
        os << this->history[i] << "\n";
    return;
}

void GameHistory::saveToFile(std::ofstream &file) const
{
    for (int i = 0; i < this->moves_num; i++)
        file << this->moves[i];
    return;
}
