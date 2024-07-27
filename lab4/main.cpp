#include <iostream>
#include "game.h"
#include "dialog.h"
#include <algorithm>
#include <vector>

using namespace std;
using namespace Chess;

int main()
{

//    //system( "chcp 65001" );
//    //system("chcp 1251");
//    //SetConsoleCP(866);
//    //SetConsoleCP(1251);
//    //setlocale(LC_ALL, "rus");
    //_setmode(_fileno(stdout), _O_U16TEXT);
//    //_setmode( _fileno( stdout ), _O_WTEXT );

    //wprintf(L"\x263b\n");
//    wcout << "Ð¿Ñ€Ð¸Ð²ÐµÑ‚\n";
//    wcout << "Ïðèâåò\n";
//    wcout << "à¨¢¥â\n";
//    wcout << "\u2654" << "\n";
//    cout << "?" << "\n";
//    cout << "?" << "\n";
//    cout << "â™”" << "\n";
//    cout << "\u263a";

    //return 0;


vector<int> a1{6,4,2,1,8,0,9,7,3,5};

sort(a1.begin(), a1.end());

//cout << a1;
cout << a1[0] << a1[1] << a1[2];
return 0;

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
