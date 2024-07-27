#include "game.h"
#include <iostream>
#include <fcntl.h>

using namespace Chess;

void Game::setupBoard()
{
    try
    {
        //kings
        this->chess_board[4][0] = new King(Piece::WHITE);
        this->chess_board[4][7] = new King(Piece::BLACK);

        //queens
        this->chess_board[3][0] = new Queen(Piece::WHITE);
        this->chess_board[3][7] = new Queen(Piece::BLACK);

        //rooks
        this->chess_board[0][0] = new Rook(Piece::WHITE);
        this->chess_board[7][0] = new Rook(Piece::WHITE);
        this->chess_board[0][7] = new Rook(Piece::BLACK);
        this->chess_board[7][7] = new Rook(Piece::BLACK);

        //knights
        this->chess_board[1][0] = new Knight(Piece::WHITE);
        this->chess_board[6][0] = new Knight(Piece::WHITE);
        this->chess_board[1][7] = new Knight(Piece::BLACK);
        this->chess_board[6][7] = new Knight(Piece::BLACK);

        //bishops
        this->chess_board[2][0] = new Bishop(Piece::WHITE);
        this->chess_board[5][0] = new Bishop(Piece::WHITE);
        this->chess_board[2][7] = new Bishop(Piece::BLACK);
        this->chess_board[5][7] = new Bishop(Piece::BLACK);

        //pawns
        for (int file = 0; file < BOARD_SIZE; file++)
            this->chess_board[file][1] = new Pawn(Piece::WHITE);
        for (int file = 0; file < BOARD_SIZE; file++)
            this->chess_board[file][6] = new Pawn(Piece::BLACK);

        //nullptrs
        for (int file = 0; file < BOARD_SIZE; file++)
            for (int rank = 2; rank < BOARD_SIZE - 2; rank++) //from 3 to 6 row
                this->chess_board[file][rank] = nullptr;
    }
    catch (std::bad_alloc e)
    {
        std::cout << e.what();
        this->resetBoard();
    }
    return;
}

void Game::resetBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (chess_board[i][j] != nullptr)
                delete chess_board[i][j], chess_board[i][j] = nullptr;
    return;
}

bool Game::checkMoveForPiece(const char file_current, const int rank_current, const char file_target, const int rank_target) const
{
    int x1 = file_current - 'a';
    int y1 = rank_current - 1;
    int x2 = file_target - 'a';
    int y2 = rank_target - 1;

    return this->checkMoveForPiece(Position(x1, y1), Position(x2, y2));
}

bool Game::checkMoveForPiece(const Position &pos_current, const Position &pos_target) const
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        throw std::invalid_argument("Invalid position");

    if (this->chess_board[pos_current.X()][pos_current.Y()] == nullptr)
        throw std::invalid_argument("There is no chess piece in this position");

    return this->chess_board[pos_current.X()][pos_current.Y()]->checkMove(pos_current, pos_target, this->chess_board);
}

GameHistory::MoveStatus Game::movePiece(const Position &pos_current, const Position &pos_target)
{
    if (pos_current.X() > BOARD_SIZE - 1 || pos_current.X() < 0 || pos_current.Y() > BOARD_SIZE - 1 || pos_current.Y() < 0
        || pos_target.X() > BOARD_SIZE - 1 || pos_target.X() < 0 || pos_target.Y() > BOARD_SIZE - 1 || pos_target.Y() < 0)
        throw std::invalid_argument("Invalid position");

    GameHistory::MoveStatus status = GameHistory::MOVE_DONE;
    if (this->chess_board[pos_target.X()][pos_target.Y()] != nullptr)
    {
        delete this->chess_board[pos_target.X()][pos_target.Y()];
        status = GameHistory::TAKEN_ENEMY_PIECE;
    }

    this->chess_board[pos_target.X()][pos_target.Y()] = this->chess_board[pos_current.X()][pos_current.Y()];
    this->chess_board[pos_current.X()][pos_current.Y()] = nullptr;
    return status;
}

bool Game::isCheck(const Piece::Color color) const
{
    Position king_pos;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (this->chess_board[i][j] != nullptr && this->chess_board[i][j]->getName() == Piece::KING
                && this->chess_board[i][j]->getColor() == color)
            {
                king_pos = Position(i, j);
                goto a;
            }
a:
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (this->chess_board[i][j] != nullptr && this->chess_board[i][j]->getColor() != color)
                if (this->chess_board[i][j]->checkMove(Position(i, j), king_pos, this->chess_board) == true)
                    return true;
    return false;
}

bool Game::isMate(const Piece::Color color) const
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (this->chess_board[i][j] != nullptr && this->chess_board[i][j]->getName() == Piece::KING
                && this->chess_board[i][j]->getColor() == color)
            {
                Position pos_king = Position(i, j);
                int list_len = 0;
                Position *pos_list = this->chess_board[i][j]->returnAvailableMoves(&list_len, Position(i, j), this->chess_board);
                if (list_len == 0)
                {
                    delete [] pos_list;
                    return true;
                }
                else
                {
                    for (int x = 0; x < list_len; x++)
                    {
                        for (int i = 0; i < BOARD_SIZE; i++)
                            for (int j = 0; j < BOARD_SIZE; j++)
                                if (this->chess_board[i][j] != nullptr && this->chess_board[i][j]->getColor() != color
                                    && this->chess_board[i][j]->getName() == Piece::BISHOP
                                    && this->chess_board[i][j]->checkReachability(Position(i, j), pos_list[x], this->chess_board) == true)
                                {
                                    for (int k = 0; k < BOARD_SIZE; k++)
                                        for (int l = 0; l < BOARD_SIZE; l++)
                                            if (this->chess_board[k][l] != nullptr && this->chess_board[k][l]->getColor() == color
                                                && this->chess_board[k][l]->checkMove(Position(k, l), Position(i, j), this->chess_board) == true)
                                            {
                                                delete [] pos_list;
                                                return false;
                                            }
                                    delete [] pos_list;
                                    return true;
                                }
                    }
                }
            }
    return false;
}

Game::Game()
{
    this->player_white.setName("Player 1");
    this->player_black.setName("Player 2");
    this->game_status = this->NO_GAME;
    this->current_game_status = this->NOTHING;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            this->chess_board[i][j] = nullptr;
    return;
}

Game::~Game()
{
    this->resetBoard();
    return;
}

void Game::setPlayersNames(const char *player_white_name, const char *player_black_name)
{
    try
    {
        this->player_white.setName(player_white_name);
        this->player_black.setName(player_black_name);
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what();
    }
    return;
}

const char *Game::getPlayerName(const Piece::Color player_color) const noexcept
{
    if (player_color == Piece::WHITE)
        return this->player_white.getName();
    return this->player_black.getName();
}

Piece::Color Game::getActivePlayerColor() const noexcept
{
    return this->active_player_color;
}

void Game::printBoardLegacy(std::ostream &os) const
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\u2503 \u2503 a  \u2503 b  \u2503 c  \u2503 d  \u2503 e  \u2503 f  \u2503 g  \u2503 h  \u2503 \u2503 ");
    _setmode(_fileno(stdout), _O_TEXT);
    this->clock.printTime(os, Clock::PLAYER_BLACK);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\n"
            "\u2523\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b\u2501\u252b ");
    _setmode(_fileno(stdout), _O_TEXT);
    os << this->player_black.getName() << " | Rating: " << this->player_black.getRating() << "\n";
    for (int file = BOARD_SIZE - 1; file >= 0; file--)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\u2503");
        _setmode(_fileno(stdout), _O_TEXT);
        os << file + 1;
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\u2503");
        for (int rank = 0; rank < BOARD_SIZE; rank++)
            if (chess_board[rank][file] != nullptr)
            {
                char name = 0, color = 0;
                int piece;
                if (this->chess_board[rank][file]->getName() == Piece::KING)
                    name = 'K';
                if (this->chess_board[rank][file]->getName() == Piece::QUEEN)
                    name = 'Q';
                if (this->chess_board[rank][file]->getName() == Piece::ROOK)
                    name = 'R';
                if (this->chess_board[rank][file]->getName() == Piece::KNIGHT)
                    name = 'N';
                if (this->chess_board[rank][file]->getName() == Piece::BISHOP)
                    name = 'B';
                if (this->chess_board[rank][file]->getName() == Piece::PAWN)
                    name = 'P';

                if (this->chess_board[rank][file]->getColor() == Piece::WHITE)
                    color = 'w';
                else
                    color = 'b';

                _setmode(_fileno(stdout), _O_TEXT);
                os << name << "(" << color << ")";
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\u2503");
            }
            else
                wprintf(L"    \u2503");
        _setmode(_fileno(stdout), _O_TEXT);
        os << file + 1;
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\u2503");
        if (file > 0)
            wprintf(L"\n\u2523\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501\u254b"
                    "\u2501\u2501\u2501\u2501"
                    "\u254b\u2501\u252b\n");
    }
    wprintf(L"\n"
            "\u2523\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b"
            "\u2501\u2501\u2501\u2501\u254b\u2501\u252b ");
    _setmode(_fileno(stdout), _O_TEXT);
    os << this->player_white.getName() << " | Rating: " << this->player_white.getRating() << "\n";
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\u2503 \u2503 a  \u2503 b  \u2503 c  \u2503 d  \u2503 e  \u2503 f  \u2503 g  \u2503 h  \u2503 \u2503 ");
    _setmode(_fileno(stdout), _O_TEXT);
    this->clock.printTime(os, Clock::PLAYER_WHITE);
    os << "\n";
    return;
}

void Game::printBoard(std::ostream &os) const
{
    os << "  | a  | b  | c  | d  | e  | f  | g  | h  |   "; this->clock.printTime(os, Clock::PLAYER_BLACK);
    os << "\n"
          "| |---------------------------------------| | "
       << this->player_black.getName() << " | Rating: " << this->player_black.getRating() << "\n";
    for (int file = BOARD_SIZE - 1; file >= 0; file--)
    {
        std::cout << "|" << file + 1 << "|";
        for (int rank = 0; rank < BOARD_SIZE; rank++)
            if (this->chess_board[rank][file] != nullptr)
            {
                char name = 0, color = 0;
                if (this->chess_board[rank][file]->getName() == Piece::KING)
                    name = 'K';
                if (this->chess_board[rank][file]->getName() == Piece::QUEEN)
                    name = 'Q';
                if (this->chess_board[rank][file]->getName() == Piece::ROOK)
                    name = 'R';
                if (this->chess_board[rank][file]->getName() == Piece::KNIGHT)
                    name = 'N';
                if (this->chess_board[rank][file]->getName() == Piece::BISHOP)
                    name = 'B';
                if (this->chess_board[rank][file]->getName() == Piece::PAWN)
                    name = 'P';

                if (this->chess_board[rank][file]->getColor() == Piece::WHITE)
                    color = 'w';
                else
                    color = 'b';

                os << name << "(" << color << ")" << "|";
            }
            else
                os << "    |";
        std::cout << file + 1 << "|";
        if (file > 0)
            os << "\n| |----+----+----+----+----+----+----+----| |\n";
    }
    os << "\n|_|---------------------------------------|_| "
       << this->player_white.getName() << " | Rating: " << this->player_white.getRating() << "\n"
       << "  | a  | b  | c  | d  | e  | f  | g  | h  |   "; this->clock.printTime(os, Clock::PLAYER_WHITE);
    os << "\n";
    return;
}

void Game::startGame()
{
    this->resetBoard();
    this->setupBoard();
    this->active_player_color = Piece::WHITE;
    this->game_status = this->GAME_ON;
    this->current_game_status = this->NOTHING;
    this->clock.reset();
    this->hisory.clearHistory();
    return;
}

Game::GameStatus Game::getGameStatus() const noexcept
{
    return this->game_status;
}

Game::CurrentGameStatus Game::getCurrentGameStatus() const noexcept
{
    return this->current_game_status;
}

bool Game::makeMove(const char file_current, const int rank_current, const char file_target, const int rank_target)
{
    int x1 = file_current - 'a';
    int y1 = rank_current - 1;
    int x2 = file_target - 'a';
    int y2 = rank_target - 1;

    return this->makeMove(Position(x1, y1), Position(x2, y2));
}

bool Game::makeMove(const int x1, const int y1, const int x2, const int y2)
{
    return this->makeMove(Position(x1, y1), Position(x2, y2));
}

bool Game::makeMove(const Position &pos_current, const Position &pos_target)
{
    if (this->chess_board[pos_current.X()][pos_current.Y()] == nullptr)
        return false;

    if (this->checkMoveForPiece(pos_current, pos_target) == true
        && this->active_player_color == this->chess_board[pos_current.X()][pos_current.Y()]->getColor())
    {
        Piece::Name name = this->chess_board[pos_current.X()][pos_current.Y()]->getName();
        GameHistory::MoveStatus move_status = this->movePiece(pos_current, pos_target);

        if (this->active_player_color == Piece::WHITE)
        {
            if (this->isCheck(Piece::BLACK) == true) //проверка на шах для противника
            {
                this->current_game_status = this->CHECK;
                if (this->isMate(Piece::BLACK) == true) //проверка на мат для противника
                {
                    this->current_game_status = this->MATE;
                    this->game_status = this->GAME_OVER;
                    this->player_white.addRating(1);
                }
            }
            else
                this->current_game_status = this->NOTHING;
            this->hisory.addHistory(pos_current, pos_target, name, move_status, name, this->current_game_status);
            this->active_player_color = Piece::BLACK;
        }
        else
        {
            if (this->isCheck(Piece::WHITE) == true) //проверка на шах для противника
            {
                this->current_game_status = this->CHECK;
                if (this->isMate(Piece::WHITE) == true) //проверка на мат для противника
                {
                    this->current_game_status = this->MATE;
                    this->game_status = this->GAME_OVER;
                    this->player_black.addRating(1);
                }
            }
            else
                this->current_game_status = this->NOTHING;
            this->hisory.appendHistory(pos_current, pos_target, name, move_status, name, this->current_game_status);
            this->active_player_color = Piece::WHITE;
        }
        return true;
    }
    return false;
}

void Game::addTimeToPreviousPlayer(const long long time_sec)
{
    if (this->active_player_color == Piece::WHITE)
        this->clock.addTimeSec(time_sec, Clock::PLAYER_BLACK);
    else
        this->clock.addTimeSec(time_sec, Clock::PLAYER_WHITE);
    return;
}

void Game::printHistory(std::ostream &os) const
{
    this->hisory.printHistory(os);
    return;
}

void Game::saveGame(std::ofstream &file) const
{
    this->hisory.saveToFile(file);
    return;
}

void Game::loadGame(std::ofstream &file) const
{

}

