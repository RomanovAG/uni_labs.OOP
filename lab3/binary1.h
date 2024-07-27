#ifndef BINARY1_H
#define BINARY1_H
#define MAX_LENGTH 74
#include <ostream>

class Binary1
{
private:
    char bin_num[MAX_LENGTH];
    int bin_num_len;

    void toBinary(const long number);
    void toBinary(const char *string, bool dot);
    void rmExtra0();
    void get(char *bin_num, int arr_len) const;

public:
    Binary1();
    Binary1(const long number);
    Binary1(const char *string, bool dot = false);

    void set(const long number);
    void set(const char *string, bool dot);
    long get() const;

    void print(std::ostream &out) const;

    int twosComplement(char *res, const int arr_len) const;

    Binary1 &add(const Binary1 &b);

    Binary1 &preIncrement();

    const Binary1 postDecrement();

    int getSign() const;
};

//void printArr(const char *arr, const int print_len, std::ostream &out);
//int sumAligned(const char *a, const char *b, const int bin_num_len, const int arr_len, const int res_arr_len, char *res);
//int sumNotAligned(const char *a, const char *b, const int a_num_len, const int b_num_len, const int arr_len, const int res_arr_len, char *res);

#endif // BINARY1_H
