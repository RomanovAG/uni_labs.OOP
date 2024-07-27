//#include <iostream>
//#include "randomiseV.hpp"

//using namespace std;

//int getNum(int *number)
//{
//    int temp = 0;
//    cin >> temp;
//    if (!cin.good())
//        return -1;
//    *number = temp;
//    return 0;
//}

//int mainold()
//{
//    const char msg[] = "1. New sampling\n"
//                       "2. Print source sampling\n"
//                       "3. Average value\n"
//                       "4. Print result sampling\n";

//    Randomise **sampling = new Randomise *;
//    *sampling = new Randomise;

//    float **new_sampling = new float *;
//    *new_sampling = new float[1];

//    int len = 0;
//    while (true)
//    {
//        system("cls");
//        cout << msg;
//        int choice = 0;
//        if (getNum(&choice) < 0 || choice < 1)
//            break;
//        if (choice == 1)
//        {
//            cout << "Enter sampling length: ";
//            if (getNum(&len) < 0 || len < 1) break;

//            delete *sampling;
//            *sampling = new Randomise(len);

//            delete [] *new_sampling;
//            *new_sampling = new float[len];

//            float average = (*sampling)->average();

//            for (int i = 0; i < (*sampling)->getlen(); i++)
//                (*new_sampling)[i] = (*sampling)->returnNumber(i) / average;
//        }
//        else if (choice == 2)
//        {
//            (*sampling)->printRandomise();
//        }
//        else if (choice == 3)
//        {
//            cout << (*sampling)->average();
//        }
//        else if (choice == 4)
//        {
//            for (int i = 0; i < len; i++)
//                cout << (*new_sampling)[i] << "\n";
//        }
//        else
//        {
//            cout << "Wrong input\n";
//        }
//        getchar();
//        getchar();
//    }
//    delete *sampling;
//    delete [] *new_sampling;

//    delete sampling;
//    delete new_sampling;

//    return 0;
//}
