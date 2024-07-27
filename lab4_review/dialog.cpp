#include "dialog.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <string>

using namespace Chess;
using namespace std;

char *getStr()
{
    string str;
    if (!getline(cin, str))
    {
        cin.clear();
        return nullptr;
    }
    char *s = new char [std::strlen(str.c_str()) + 1];

    std::strcpy(s, str.c_str());

    return s;
}

int getNum(int *number)
{
    int temp = 0;
    cin >> temp;
    if (!cin.good())
        return -1;
    *number = temp;
    return 0;
}

int getChar(char *symbol)
{
    char temp = 0;
    cin >> temp;
    if (cin.bad())
        return -1;
    *symbol = temp;
    return 0;
}

int dStart(Game &game)
{
    game.startGame();
    return dContinue(game);
}

int dContinue(Game &game)
{
    while (game.getGameStatus() == Game::GAME_ON)
    {
        system("cls");
        game.printBoardLegacy(cout);

        cout << "\n";
        if (game.getActivePlayerColor() == Piece::WHITE)
            cout << "Enter your move, " << game.getPlayerName(game.getActivePlayerColor()) << " (white): ";
        else
            cout << "Enter your move, " << game.getPlayerName(game.getActivePlayerColor()) << " (black): ";

        char file_current = 0;
        int rank_current = 0;
        char file_target = 0;
        int rank_target = 0;

        clock_t start = clock();
        cin >> file_current >> rank_current >> file_target >> rank_target;
        if (!cin.good())
            return 0;

        bool move = game.makeMove(file_current, rank_current, file_target, rank_target);
        clock_t end = clock();

        if (move == true)
            game.addTimeToPreviousPlayer((end - start) / CLOCKS_PER_SEC);
    }
    if (game.getGameStatus() == Game::GAME_OVER)
    {
        system("cls");
        game.printBoardLegacy(cout);
        cout << "\n"
                "GAME OVER!"
                "\n";
        getchar();
        getchar();
    }
    return 0;
}

int dChangePlNames(Game &game)
{
    cout << "\n";
    cout << "Enter the name of the player playing for white: ";
    getchar();
    char *player_white = getStr();
    cout << "Enter the name of the player playing for black: ";
    char *player_black = getStr();
    if(player_white == nullptr || player_black == nullptr)
    {
        delete [] player_white;
        delete [] player_black;
        return 0;
    }

    game.setPlayersNames(player_white, player_black);
    delete [] player_white;
    delete [] player_black;
    return 0;
}

int dPrintHistory(Game &game)
{
    game.printHistory(cout);
    getchar();
    getchar();
    return 0;
}

int dSaveGame(Game &game)
{
    cout << "Enter file name: ";
    getchar();
    char *file_name = getStr();
    if(file_name == nullptr)
        return 0;

    std::ofstream file;
    file.open(file_name, std::ios::out);
    try
    {
        game.saveGame(file);
    }
    catch (std::invalid_argument e)
    {
        cout << e.what();
    }
    file.close();
    delete [] file_name;
    return 0;
}

int dLoadGame(Game &game)
{
    cout << "Enter file name: ";
    getchar();
    char *file_name = getStr();
    if(file_name == nullptr)
        return 0;

    std::ifstream file;
    file.open(file_name, std::ios::in);

    char move[9] = {0};

    game.startGame();

    while (true)
    {
        move[0] = file.get();
        move[1] = file.get();
        move[2] = file.get();
        move[3] = file.get();
        move[4] = file.get();
        move[5] = file.get();
        move[6] = file.get();
        move[7] = file.get();
        move[8] = '\0';
        if (file.eof() == true)
            break;

        game.makeMove(move[0], move[2] - 48, move[4], move[6] - 48); //'1' - 48 == 1, '2' - 48 == 2 ...
    }
    file.close();
    getchar();
    delete [] file_name;
    return 0;
}
