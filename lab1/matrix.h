#ifndef MATRIX_H
#define MATRIX_H

struct Matrix
{
    int m;
    int n;
    int **matr;
};

Matrix *input();
Matrix *solve(const Matrix *src_matrix);
int printResult(const Matrix *src_matrix, const Matrix *res_matrix);
void erase(Matrix *matrix);

#endif // MATRIX_H
