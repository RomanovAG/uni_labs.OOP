#include <iostream>
#include "randomiseV.hpp"
#include <time.h>

using namespace std;

int getNum(int *number)
{
    int temp = 0;
    cin >> temp;
    if (!cin.good())
        return -1;
    *number = temp;
    return 0;
}

int main()
{
    srand(time(NULL));
    while (true)
    {
        system("cls");
        int l1, l2;
        cout << "Player 1\n"
                "Enter number from 1 to 100: ";
        if (getNum(&l1) < 0 || l1 < 1 || l1 > 100)
            break;
        cout << "Player 2\n"
                "Enter number from 1 to 100: ";
        if (getNum(&l2) < 0 || l2 < 1 || l2 > 100)
            break;
        Randomise rand1(l1);
        Randomise rand2(l2);
        float avg1 = rand1.average();
        float avg2 = rand2.average();

        float relative1 = (avg1 - 0.0) / (1.0 - 0.0);
        float relative2 = (avg2 - 0.0) / (1.0 - 0.0);

        float scaled1 = 1.0 + (6.0 - 1.0) * relative1;
        float scaled2 = 1.0 + (6.0 - 1.0) * relative2;

        float res1 = round(scaled1);
        float res2 = round(scaled2);

        cout << "\n";
        cout << "Player 1: " << res1 << "\n";
        cout << "Player 2: " << res2 << "\n";

        if (res1 > res2)
            cout << "Player 1 wins!\n";
        else if (res1 < res2)
            cout << "Player 2 wins!\n";
        else
            cout << "Draw. . .\n";
        getchar();
        getchar();
    }
    return 0;
}
