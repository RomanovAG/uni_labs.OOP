#include <iostream>
#include "matrix.h"

int main()
{
    while (true)
    {
        system("cls");
        Matrix *src_matrix = input();
        Matrix *res_matrix = solve(src_matrix);
        int res = printResult(src_matrix, res_matrix);
        erase(src_matrix);
        erase(res_matrix);
        if (res < 0)
            return 0;
    }
}
