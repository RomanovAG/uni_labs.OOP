#include <iostream>
#include "matrix.h"

int main()
{
    while (true)
    {
        system("cls");
        Matrix *src_matrix = matr::set();
        if (src_matrix == nullptr)
            return 0;
        while (true)
            if (matr::input(src_matrix) < 0)
                break;
        Matrix *res_matrix = matr::solve(src_matrix);
        matr::printResult(src_matrix, res_matrix);
        matr::erase(src_matrix);
        matr::erase(res_matrix);
    }
}
