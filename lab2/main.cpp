#include <iostream>
#include "conchoidnicomed.h"
#include "dialog.h"

using namespace std;

int main()
{
    ConchoidNicomed CN(1, 1);
    while (true)
    {
        system("cls");
        cout << "1. Set l\n"
                "2. Set a\n"
                "3. Show l and a\n"
                "4. Return Y\n"
                "5. Return R\n"
                "6. Return Curvature radius\n"
                "7. Return area\n"
                "8. Return inflection points\n"
                ">";
        int choice = 0;
        if (getInt(&choice) < 0 || choice <= 0)
            break;
        if (choice == 1)
        {
            cout << "Enter l: ";
            double l = 0;
            if (getDouble(&l) < 0)
                break;
            try
            {
                CN.setL(l);
            }
            catch (std::invalid_argument e)
            {
                cout << e.what() << "\n";
            }
        }
        if (choice == 2)
        {
            cout << "Enter a: ";
            double a = 0;
            if (getDouble(&a) < 0)
                break;
            CN.setA(a);
        }
        if (choice == 3)
        {
            cout << "l: " << CN.getL() << "\na: " << CN.getA();
        }
        if (choice == 4)
        {
            cout << "Enter X: ";
            double x;
            if (getDouble(&x) < 0)
                break;
            double y1 = 0, y2 = 0;
            CN.returnY(x, &y1, &y2);
            cout << "y1: " << y1 << "\ny2: " << y2;
        }
        if (choice == 5)
        {
            cout << "Enter fi: ";
            double fi;
            if (getDouble(&fi) < 0)
                break;
            double r1 = 0, r2 = 0;
            CN.returnR(CN.degToRad(fi), &r1, &r2);
            cout << "r1: " << r1 << "\nr2: " << r2;
        }
        if (choice == 6)
        {
            double r_A = 0, r_C = 0, r_O = 0;
            CN.returnCurvRads(&r_A, &r_C, &r_O);
            if (isnan(r_A) == false)
                cout << "Ra: " << r_A << "\n";
            if (isnan(r_C) == false)
                cout << "Rc: " << r_C << "\n";
            if (isnan(r_O) == false)
                cout << "Ro: " << r_O << "\n";
        }
        if (choice == 7)
        {
            double area = CN.returnArea();
            cout << "Loop area: " << area;
        }
        if (choice == 8)
        {
            double x1;
            double x2;
            double x3;
            double x4;
            double y1;
            double y2;
            double y3;
            double y4;
            CN.returnIP(&x1, &x2, &x3, &x4);
            CN.returnY(x1, &y1, nullptr);
            CN.returnY(x2, nullptr, &y2);
            CN.returnY(x3, &y3, nullptr);
            CN.returnY(x4, nullptr, &y4);

            cout << "x1: " << x1 << " | y1: " << y1 << "\n";
            cout << "x2: " << x2 << " | y2: " << y2 << "\n";
            if (isnan(x3) == false)
                cout << "x3: " << x3 << " | y3: " << y3 << "\n";
            if (isnan(x4) == false)
                cout << "x4: " << x4 << " | y4: " << y4 << "\n";
        }
        getchar();
        getchar();
    }
    return 0;
}
