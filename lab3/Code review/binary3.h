#ifndef BINARY3_H
#define BINARY3_H
#include <ostream>

class Binary3
{
private:
    char *bin_num;
    int bin_num_len;

    void toBinary(const long number);
    void toBinary(const char *string, bool dot);
    void rmExtra0();
    void get(char *bin_num, int arr_len) const;
    Binary3 &add(const Binary3 &b);

public:
    Binary3();
    Binary3(const Binary3 &bin);
    Binary3(const long number);
    Binary3(const char *string, bool dot = false);
    ~Binary3();

    void set(const long number);
    void set(const char *string, bool dot);
    long get() const;

    void print(std::ostream &out) const;

    int twosComplement(char *res, const int arr_len) const;

    const Binary3 operator +(const Binary3 &b) const;

    Binary3 &operator ++();

    const Binary3 operator --(int);

    int getSign() const;

    Binary3 &operator =(const Binary3 &b);
};

#endif // BINARY3_H
