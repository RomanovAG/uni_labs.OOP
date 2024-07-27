#include <iostream>
#include "game.h"
#include "dialog.h"

using namespace std;
using namespace Chess;

int main()
{
    Game game;
    const char menu[] = "0. Exit\n"
                        "1. Start new game\n"
                        "2. Continue game\n"
                        "3. Change players' names\n"
                        "4. Print game history\n"
                        "5. Save game\n"
                        "6. Load game\n"
                        ">";

    while (true)
    {
        system("cls");
        cout << menu;
        int choice = 0;

        if (getNum(&choice) < 0 || choice < 1 || choice > 6)
            break;

        if (choice == 1)
        {
            if (dStart(game) < 0)
                break;
        }
        else if (choice == 2)
        {
            if (dContinue(game) < 0)
                break;
        }
        else if (choice == 3)
        {
            if (dChangePlNames(game) < 0)
                break;
        }
        else if (choice == 4)
        {
            if (dPrintHistory(game) < 0)
                break;
        }
        else if (choice == 5)
        {
            if (dSaveGame(game) < 0)
                break;
        }
        else if (choice == 6)
        {
            if (dLoadGame(game) < 0)
                break;
        }
        cin.clear();
    }
    return 0;
}
