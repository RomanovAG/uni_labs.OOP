#include <iostream>
#include "matrix.h"

struct OutputMatrix
{
    int m = 0;
    int n = 0;
    int **matr = nullptr;
};

int getInt(int *value)
{
    int temp;
    std::cin >> temp;
    if (std::cin.fail())
    {
        std::cin.clear();
        return -1;
    }
    *value = temp;
    return 0;
}

int add(Matrix *matrix, int row, int column, int value);

Matrix *matr::set()
{
    int m, n;
    std::cout << "Enter number of lines: ";
    if (getInt(&m) < 0 || m < 0)
    {
        std::cout << "Incorrect input\n";
        return nullptr;
    }
    if (m == 0)
    {
        Matrix *matrix = new Matrix;
        matrix->m = rand() % 6 + 15;
        matrix->n = rand() % 6 + 15;;
        matrix->head = nullptr;
        for (int i = 0; i < rand() % matrix->m + matrix->m; i++)
        {
            add(matrix, rand() % matrix->m + 1, rand() % matrix->n + 1, rand() % 1000);
        }
        return matrix;
    }
    std::cout << "Enter number of columns: ";
    if (getInt(&n) < 0 || n <= 0)
    {
        std::cout << "Incorrect input\n";
        return nullptr;
    }
    Matrix *matrix = new Matrix;
    matrix->m = m;
    matrix->n = n;
    matrix->head = nullptr;
    return matrix;
}

Element *findEl(Element *head, int x, int y)
{
    Element *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->row == x && ptr->column == y)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

int add(Matrix *matrix, int row, int column, int value)
{
    if (matrix == nullptr)
        return -1;
    Element *existedEl = findEl(matrix->head, row, column);
    if (existedEl == nullptr)
    {
        Element *el = new Element;
        el->row = row;
        el->column = column;
        el->value = value;
        el->next = matrix->head;
        matrix->head = el;
    }
    else
        existedEl->value = value;
    return 0;
}

int matr::input(Matrix *matrix)
{
    if (matrix == nullptr)
        return -1;
    int row, column, value;
    std::cout << "Enter row: ";
    if (getInt(&row) < 0 || row > matrix->m)
    {
        std::cout << "Incorrect input (must be between 1 and " << matrix->m << ")\n";
        return -1;
    }
    std::cout << "Enter column: ";
    if (getInt(&column) < 0 || column > matrix->n)
    {
        std::cout << "Incorrect input (must be between 1 and " << matrix->n << ")\n";
        return -1;
    }
    std::cout << "Enter value: ";
    if (getInt(&value) < 0)
    {
        std::cout << "Incorrect input\n";
        return -1;
    }
    if (add(matrix, row, column, value) < 0)
        return -1;
    return 0;
}

int matr::erase(Matrix *matrix)
{
    if (matrix == nullptr)
        return 1;
    if (matrix->head == nullptr)
    {
        delete matrix;
        return 0;
    }
    Element *ptr = matrix->head, *ptr_prev;
    while (ptr != nullptr)
    {
        ptr_prev = ptr;
        ptr = ptr->next;
        delete ptr_prev;
    }
    delete matrix;
    return 0;
}

int matr::printList(const Matrix *matrix)
{
    if (matrix == nullptr)
        return 1;
    Element *ptr = matrix->head;
    while (ptr != nullptr)
    {
        std::cout << "Row: " << ptr->row << " Column: " << ptr->column<< " Value: " << ptr->value << "\n";
        ptr = ptr->next;
    }
    return 0;
}

void printMatrix(const OutputMatrix *matrix);

int printListAsMatrix(const Matrix *input)
{
    if (input == nullptr)
        return 1;
    int **matr = new int * [input->m];
    for (int i = 0; i < input->m; i++)
    {
        matr[i] = new int [input->n];
    }
    for (int i = 0; i < input->m; i++)
        for (int j = 0; j < input->n; j++)
            matr[i][j] = 0;
    Element *ptr = input->head;
    while (ptr != nullptr)
    {
        matr[ptr->row - 1][ptr->column - 1] = ptr->value;
        ptr = ptr->next;
    }
    OutputMatrix matrix = {input->m, input->n, matr};
    printMatrix(&matrix);
    delete [] matr;
    return 0;
}

int matr::printResult(const Matrix *src_matrix, const Matrix *res_matrix)
{
    if (src_matrix == nullptr)
    {
        std::cout << "Source matrix is empty";
        getchar();
        return 1;
    }
    std::cout << "\n"
                 "Source matrix: \n\n";
    if (src_matrix->m <= 25)
        printListAsMatrix(src_matrix);
    else
        printList(src_matrix);
    if (res_matrix == nullptr)
        return 1;
    std::cout << "\n"
                 "Result matrix: \n\n";
    if (res_matrix->m <= 25)
        printListAsMatrix(res_matrix);
    else
        printList(res_matrix);
    std::cout << "Press enter to continue . . .";
    getchar();
    return 0;
}

template <typename T>
T absolute(T input)
{
    if (input < 0)
        return -input;
    return input;
}

template <typename TYPE_1>
bool cond_1(TYPE_1 value)
{
    while (absolute(value) > 0)
    {
        if (value % 2 != 0)
            return false;
        value /= 10;
    }
    return true;
}

template <typename TYPE_2>
bool cond_2(TYPE_2 value)
{
    while (absolute(value) > 0)
    {
        if (value % 10 <= 5)
            return false;
        value /= 10;
    }
    return true;
}

Matrix *matr::solve(const Matrix *src_matrix)
{
    if (src_matrix == nullptr || src_matrix->head == nullptr)
        return nullptr;
    Matrix *res_matrix = new Matrix;
    res_matrix->m = src_matrix->m;
    res_matrix->n = src_matrix->n;
    res_matrix->head = nullptr;
    Element *ptr = src_matrix->head;
    while (ptr != nullptr)
    {
        if (cond_1(ptr->value) == true)
        {
            Element *el = new Element;
            el->row = ptr->row;
            el->column = ptr->column;
            el->value = ptr->value;
            el->next = res_matrix->head;
            res_matrix->head = el;
        }
        ptr = ptr->next;
    }
    return res_matrix;
}

template <typename D>
int digits(D input)
{
    int digits = 0;
    if (input == 0)
        return 1;
    while (absolute(input) > 0)
    {
        input /= 10;
        digits++;
    }
    return digits;
}

int findMax(const OutputMatrix *matrix)
{
    int max_value = matrix->matr[0][0];
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            if (absolute(matrix->matr[i][j]) > absolute(max_value))
                max_value = matrix->matr[i][j];
    return max_value;
}

int findBelowZero(const OutputMatrix *matrix)
{
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            if (matrix->matr[i][j] < 0)
                return -1;
    return 1;
}

void printMatrix(const OutputMatrix *matrix)
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
