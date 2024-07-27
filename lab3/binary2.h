#ifndef BINARY2_H
#define BINARY2_H
#define MAX_LENGTH 74
#include <ostream>

class Binary2
{
private:
    char bin_num[MAX_LENGTH];
    int bin_num_len;

    void toBinary(const long number);
    void toBinary(const char *string, bool dot);
    void rmExtra0();
    void get(char *bin_num, int arr_len) const;
    Binary2 &add(const Binary2 &b);

public:
    Binary2();
    Binary2(const long number);
    Binary2(const char *string, bool dot = false);

    void set(const long number);
    void set(const char *string, bool dot);
    long get() const;

    void print(std::ostream &out) const;

    int twosComplement(char *res, const int arr_len) const;

    const Binary2 operator +(const Binary2 &b) const;

    Binary2 &operator ++();

    const Binary2 operator --(int);

    int getSign() const;
};

#endif // BINARY2_H
