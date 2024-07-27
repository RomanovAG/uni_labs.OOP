#include <iostream>
#include "matrix.h"

int getInt(int *value)
{
    int temp;
    std::cin >> temp;
    if (std::cin.fail())
    {
        std::cin.ignore(INT_MAX);
        return -1;
    }
    *value = temp;
    return 0;
}

void erase(Matrix *matrix)
{
    if (matrix != nullptr)
    {
        if (matrix->matr != nullptr)
            for (int i = 0; i < matrix->m; i++)
                if (matrix->matr[i] != nullptr)
                    delete [] matrix->matr[i];
        delete [] matrix->matr;
        delete matrix;
    }
}

void printMatrix(const Matrix *matrix);

Matrix *input()
{
    Matrix *matrix = new Matrix;
    std::cout << "Enter number of lines: ";
    if (getInt(&matrix->m) < 0)
    {
        std::cout << "Incorrect input\n";
        delete matrix;
        return nullptr;
    }
    std::cout << "Enter number of columns: ";
    if (getInt(&matrix->n) < 0)
    {
        std::cout << "Incorrect input\n";
        delete matrix;
        return nullptr;
    }
    try
    {
        matrix->matr = new int * [matrix->m];
        for (int i = 0; i < matrix->m; i++)
            matrix->matr[i] = new int [matrix->n];
    }
    catch (const std::exception &msg)
    {
        std::cerr << msg.what() << "\n";
        erase(matrix);
        return nullptr;
    }
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            matrix->matr[i][j] = 0;
    //printMatrix(matrix);
    for (int i = 0; i < matrix->m; i++)
    {
        std::cout << "Enter line " << i + 1 << ":\n";
        for (int j = 0; j < matrix->n; j++)
            if (getInt(&matrix->matr[i][j]) < 0)
            {
                std::cout << "Incorrect input\n";
                erase(matrix);
                return nullptr;
            }
    }
    return matrix;
}

bool cond_1(int value)
{
    while (abs(value) > 0)
    {
        if (value % 2 != 0)
            return false;
        value /= 10;
    }
    return true;
}

bool cond_2(int value)
{
    while (abs(value) > 0)
    {
        if (value % 10 <= 5)
            return false;
        value /= 10;
    }
    return true;
}

Matrix *solve(const Matrix *src_matrix)
{
    if (src_matrix == nullptr)
        return nullptr;
    Matrix *res_matrix = new Matrix;
    res_matrix->m = src_matrix->m;
    res_matrix->n = src_matrix->n;
    res_matrix->matr = new int * [res_matrix->m];
    for (int i = 0; i < res_matrix->m; i++)
        res_matrix->matr[i] = new int [res_matrix->n];
    for (int i = 0; i < res_matrix->m; i++)
        for (int j = 0; j < res_matrix->n; j++)
        {
            if (cond_1(src_matrix->matr[i][j]) == true)
                res_matrix->matr[i][j] = src_matrix->matr[i][j];
            else
                res_matrix->matr[i][j] = 0;
        }
    return res_matrix;
}

int digits(long input)
{
    int digits = 0;
    if (input == 0)
        return 1;
    while (labs(input) > 0)
    {
        input /= 10;
        digits++;
    }
    return digits;
}

int findMax(const Matrix *matrix)
{
    int max_value = matrix->matr[0][0];
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            if (labs(matrix->matr[i][j]) > labs(max_value))
                max_value = matrix->matr[i][j];
    return max_value;
}

int findBelowZero(const Matrix *matrix)
{
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            if (matrix->matr[i][j] < 0)
                return -1;
    return 1;
}

void printMatrix(const Matrix *matrix)
{
    if (matrix == nullptr || matrix->matr == nullptr || matrix->m == 0 || matrix->n == 0)
        return;
    int max_value = findMax(matrix);
    short fbz = findBelowZero(matrix);
    int dmv = digits(max_value);
    for (int i = 0; i < matrix->m; i++)
    {
        for (int j = 0; j < matrix->n; j++)
        {
            if (digits(matrix->matr[i][j]) < dmv)
            {
                for (int x = 0; x < dmv - digits(matrix->matr[i][j]); x++)
                    std::cout << " ";
            }
            if (fbz < 0 && matrix->matr[i][j] >= 0)
                std::cout << " ";
            std::cout << matrix->matr[i][j] << " ";
        }
        std::cout << "\n\n";
    }
}

int printResult(const Matrix *src_matrix, const Matrix *res_matrix)
{
    if (src_matrix == nullptr || src_matrix->matr == nullptr || src_matrix->m == 0 || src_matrix->n == 0)
    {
        std::cout << "Source matrix is empty\n";
        std::cout << "Press enter to continue . . .";
        getchar();
        return -1;
    }
    std::cout << "\n"
                 "Source matrix:\n\n";
    printMatrix(src_matrix);
    if (res_matrix == nullptr)
    {
        std::cout << "Press enter to continue . . .";
        getchar();
        return -1;
    }
    std::cout << "\n"
                 "Result matrix:\n\n";
    printMatrix(res_matrix);
    std::cout << "Press enter to continue . . .";
    getchar();
    getchar();
    return 0;
}
