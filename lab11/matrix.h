#ifndef MATRIX_H
#define MATRIX_H

struct Element
{
    int row = 0;
    int column = 0;
    int value = 0;
    Element *next = nullptr;
};

struct Matrix
{
    int m = 0;
    int n = 0;
    Element *head = nullptr;
};

namespace matr
{
Matrix *set();
int input(Matrix *matrix);
Matrix *solve(const Matrix *src_matrix);
int printList(const Matrix *matrix);
int printResult(const Matrix *src_matrix, const Matrix *res_matrix);
int erase(Matrix *matrix);
}

#endif // MATRIX_H
