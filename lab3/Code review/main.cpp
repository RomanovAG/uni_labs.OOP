#include <iostream>
#include "binary1.h"
#include "binary2.h"
#include "binary3.h"

using namespace std;

int getNum(long *number)
{
    long temp = 0;
    cin >> temp;
    if (!cin.good())
        return -1;
    *number = temp;
    return 0;
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

int main()
{
    const char msg[] = " 1. New binary number (empty constructor)\n"
                       " 2. New binary number (long int constructor)\n"
                       " 3. New binary number (string constructor)\n"
                       " 4. Set value (long int)\n"
                       " 5. Set value (string)\n"
                       " 6. Print number\n"
                       " 7. Return two’s complement of number\n"
                       " 8. Add number\n"
                       " 9. Pre-increment\n"
                       "10. Post-decrement\n"
                       "11. Get sign of number\n";
    while (true)
    {
        system("cls");
        cout << "1. Binary1 menu\n"
                "2. Binary2 menu\n"
                "3. Binary3 menu\n"
                ">";
        int choice = 0;
        if (getNum(&choice) < 0 || choice < 1)
            break;
        Binary1 bin1;
        Binary2 bin2;
        Binary3 bin3;
        if (choice == 1)
            while (true)
            {
                system("cls");
                cout << msg << ">";
                int b1_choice;
                if (getNum(&b1_choice) < 0 || choice < 1)
                    break;
                switch (b1_choice)
                {
                case 1:
                {
                    bin1.set(0);
                    break;
                }
                case 2:
                {
                    cout << "Enter number: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin1.set(number);
                    break;
                }
                case 3:
                {
                    cout << "Enter binary number: ";
                    char buf[80] = {0};
                    scanf("%s", buf);
                    bin1.set(buf, true);
                    break;
                }
                case 4:
                {
                    cout << "Enter number: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin1.set(number);
                    break;
                }
                case 5:
                {
                    cout << "Enter binary number: ";
                    char buf[80] = {0};
                    scanf("%s", buf);
                    bin1.set(buf, true);
                    break;
                }
                case 6:
                {
                    bin1.print(cout);
                    getchar();
                    break;
                }
                case 7:
                {
                    char buf[80] = {0};
                    int len = 80;
                    int num_len = bin1.twosComplement(buf, len);
                    cout << (int) buf[0] << ".";
                    for (int i = 1; i < num_len; i++)
                    {
                        cout << (int) buf[i];
                    }
                    getchar();
                    break;
                }
                case 8:
                {
                    cout << "Enter number to add: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin1.add(Binary1(number));
                    break;
                }
                case 9:
                {
                    bin1.preIncrement();
                    break;
                }
                case 10:
                {
                    bin1.postDecrement();
                    break;
                }
                case 11:
                {
                    cout << bin1.getSign();
                    getchar();
                    break;
                }
                default:
                    break;
                }
                getchar();
            }
        if (choice == 2)
            while (true)
            {
                system("cls");
                cout << msg << ">";
                int b1_choice;
                if (getNum(&b1_choice) < 0 || choice < 1)
                    break;
                switch (b1_choice)
                {
                case 1:
                {
                    bin2.set(0);
                    break;
                }
                case 2:
                {
                    cout << "Enter number: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin2.set(number);
                    break;
                }
                case 3:
                {
                    cout << "Enter binary number: ";
                    char buf[80] = {0};
                    scanf("%s", buf);
                    bin2.set(buf, true);
                    break;
                }
                case 4:
                {
                    cout << "Enter number: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin2.set(number);
                    break;
                }
                case 5:
                {
                    cout << "Enter binary number: ";
                    char buf[80] = {0};
                    scanf("%s", buf);
                    bin2.set(buf, true);
                    break;
                }
                case 6:
                {
                    bin2.print(cout);
                    getchar();
                    break;
                }
                case 7:
                {
                    char buf[80] = {0};
                    int len = 80;
                    int num_len = bin2.twosComplement(buf, len);
                    cout << (int) buf[0] << ".";
                    for (int i = 1; i < num_len; i++)
                    {
                        cout << (int) buf[i];
                    }
                    getchar();
                    break;
                }
                case 8:
                {
                    cout << "Enter number to add: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin2 = bin2 + Binary2(number);
                    break;
                }
                case 9:
                {
                    ++bin2;
                    break;
                }
                case 10:
                {
                    (bin2--).print(cout);
                    getchar();
                    break;
                }
                case 11:
                {
                    cout << bin2.getSign();
                    getchar();
                    break;
                }
                default:
                    break;
                }
                getchar();
            }
        if (choice == 3)
            while (true)
            {
                system("cls");
                cout << msg << ">";
                int b1_choice;
                if (getNum(&b1_choice) < 0 || choice < 1)
                    break;
                switch (b1_choice)
                {
                case 1:
                {
                    bin3.set(0);
                    break;
                }
                case 2:
                {
                    cout << "Enter number: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin3.set(number);
                    break;
                }
                case 3:
                {
                    cout << "Enter binary number: ";
                    char buf[80] = {0};
                    scanf("%s", buf);
                    bin3.set(buf, true);
                    break;
                }
                case 4:
                {
                    cout << "Enter number: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin3.set(number);
                    break;
                }
                case 5:
                {
                    cout << "Enter binary number: ";
                    char buf[80] = {0};
                    scanf("%s", buf);
                    bin3.set(buf, true);
                    break;
                }
                case 6:
                {
                    bin3.print(cout);
                    getchar();
                    break;
                }
                case 7:
                {
                    char buf[80] = {0};
                    int len = 80;
                    int num_len = bin3.twosComplement(buf, len);
                    cout << (int) buf[0] << ".";
                    for (int i = 1; i < num_len; i++)
                    {
                        cout << (int) buf[i];
                    }
                    getchar();
                    break;
                }
                case 8:
                {
                    cout << "Enter number to add: ";
                    long number = 0;
                    if (getNum(&number) < 0)
                        break;
                    bin3 = bin3 + Binary3(number);
                    break;
                }
                case 9:
                {
                    ++bin3;
                    break;
                }
                case 10:
                {
                    bin3--;
                    break;
                }
                case 11:
                {
                    cout << bin3.getSign();
                    getchar();
                    break;
                }
                }
                getchar();
            }
        cin.clear();
    }
    return 0;
}
