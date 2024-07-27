#include "binary1.h"
#include <cstring>
//#include <iostream>

//using namespace std;

void Binary1::toBinary(const long number)
{
    int arr_len = sizeof (this->bin_num) / sizeof (char);
    memset(this->bin_num, 0, arr_len);
    long temp = labs(number);
    this->bin_num_len = 2;
    this->bin_num[1] = temp % 2;
    temp /= 2;
    while (temp > 0)
    {
        memmove(&this->bin_num[2], &this->bin_num[1], this->bin_num_len);
        this->bin_num[1] = temp % 2;
        temp /= 2;
        this->bin_num_len++;
        if (this->bin_num_len >= arr_len)
            throw std::overflow_error("the maximum allowed number size has been exceeded");
    }
    if (number < 0)
        this->bin_num[0] = 1;
    else
        this->bin_num[0] = 0;
    //this->bin_num_len++;
    //printf("bnl: %d\n", this->bin_num_len);
    return;
}

void Binary1::toBinary(const char *string, bool dot)
{
    memset(this->bin_num, 0, sizeof (this->bin_num));
    if (dot == false)
    {
        for (int i = 0; i < strlen(string); i++)
        {
            if (string[i] == '0')
                this->bin_num[i] = 0;
            else if (string[i] == '1')
                this->bin_num[i] = 1;
            else
                throw std::invalid_argument("not a binary number");
        }
        this->bin_num_len = strlen(string);
    }
    else
    {
        for (int i = 0; i < strlen(string); i++)
            if (string[i] != '0' && string[i] != '1')
                if (string[i] == '.' && i != 1 || string[i] != '.')
                    throw std::invalid_argument("not a binary number");
        if (strlen(string) == 1)
            throw std::bad_alloc();
        char *no_dot_str = new char[strlen(string) - 1];
        no_dot_str[0] = string[0];
        memcpy(&no_dot_str[1], &string[2], strlen(string) - 1);

        //printf("no dot str: %s\n", no_dot_str);
        //printf("dn len: %d\n", strlen(no_dot_str));

        for (int i = 0; i < strlen(no_dot_str); i++)
        {
            if (no_dot_str[i] == '0')
                this->bin_num[i] = 0;
            else if (no_dot_str[i] == '1')
                this->bin_num[i] = 1;
            else
                throw std::invalid_argument("not a binary number");
        }
        this->bin_num_len = strlen(no_dot_str);
        delete [] no_dot_str;
    }
    return;
}

void Binary1::rmExtra0()
{
    while (this->bin_num[1] == 0 && bin_num_len > 2)
    {
        memmove(&this->bin_num[1], &this->bin_num[2], this->bin_num_len - 2);
        this->bin_num[this->bin_num_len - 1] = 0;
        this->bin_num_len--;
    }
}

void Binary1::get(char *bin_num, int arr_len) const
{
    if (arr_len < this->bin_num_len)
        throw std::overflow_error("not enough length");
    memset(bin_num, 0, arr_len);
    memcpy(bin_num, this->bin_num, arr_len);
}

Binary1::Binary1()
{
    memset(this->bin_num, 0, sizeof (this->bin_num));
    this->bin_num_len = 2;
}

Binary1::Binary1(const long number)
{
    this->toBinary(number);
}

Binary1::Binary1(const char *string, bool dot)
{
    this->toBinary(string, dot);
    this->rmExtra0();
}

void Binary1::set(const long number)
{
    this->toBinary(number);
}

void Binary1::set(const char *string, bool dot)
{
    this->toBinary(string, dot);
    this->rmExtra0();
}

long Binary1::get() const
{
    long res = 0;
    for (int i = 1; i < this->bin_num_len; i++)
    {
        res *= 2;
        res += this->bin_num[i];
    }
    if (this->bin_num[0] == 1)
        return -res;
    return res;
}

namespace Bin1
{
int sumAligned(const char *a, const char *b, const int bin_num_len, const int arr_len, char *res)
{
    memset(res, 0, arr_len);

    //    cout << "x: ";
    //    printArr(a, new_bin_num_len, cout);
    //    cout << "\ny: ";
    //    printArr(b, new_bin_num_len, cout);

    for (int i = 0; i < bin_num_len; i++)
        res[i] = a[i] + b[i];

    for (int i = bin_num_len - 1; i > 0; i--)
        if (res[i] > 1)
        {
            char transfer = res[i] / 2;
            res[i] = res[i] % 2;
            //            if (i - 1 == 0)
            //            {
            //                memmove(&res[2], &res[1], new_bin_num_len - 1);
            //                res[1] = transfer;
            //                new_bin_num_len++;
            //                if (new_bin_num_len > res_arr_len)
            //                    throw std::overflow_error("not enough length: in function sumAligned()");
            //                i++;
            //            }
            //            else
            res[i - 1] += transfer;

        }
    res[0] = res[0] % 2;
    //cout << "\nsum :";
    //printArr(res, new_bin_num_len, cout);
    //cout << "\n";
    return bin_num_len;
}

int alignLen(char *res, const int res_num_len, const int src_num_len, const int arr_len)
{
    if (res_num_len > arr_len)
        throw std::overflow_error("not enough length: in function alignLen()");
    if (res_num_len == src_num_len)
        return res_num_len;
    memmove(&res[res_num_len - src_num_len + 1], &res[1], src_num_len - 1);
    memset(&res[1], 0, res_num_len - src_num_len);
    return res_num_len;
}

//int sumNotAligned(const char *a, const char *b, const int a_num_len, const int b_num_len, const int arr_len, const int res_arr_len, char *res)
//{
//    int target_bin_num_len = a_num_len >= b_num_len ? a_num_len : b_num_len;
//    char a_aligned[arr_len], b_aligned[arr_len];
//    memcpy(a_aligned, a, arr_len);
//    memcpy(b_aligned, b, arr_len);
//    alignLen(a_aligned, target_bin_num_len, a_num_len, arr_len);
//    alignLen(b_aligned, target_bin_num_len, b_num_len, arr_len);
//    int new_bin_num_len = sumAligned(a_aligned, b_aligned, target_bin_num_len, arr_len, res_arr_len, res);
//    return new_bin_num_len;
//}

int twosComplement(char *res, const char *src, const int bin_num_len, const int arr_len)
{
    memset(res, 0, arr_len);
    if (src[0] == 0)
    {
        memcpy(res, src, bin_num_len);
        return bin_num_len;
    }
    char *rev_code = new char[arr_len];
    memset(rev_code, 0, arr_len);
    rev_code[0] = src[0];

    for (int i = 1; i < bin_num_len; i++)
        rev_code[i] = !src[i];

    rev_code[bin_num_len - 1] += 1;
    for (int i = bin_num_len - 1; i > 0; i--)
        if (rev_code[i] > 1)
        {
            char transfer = rev_code[i] / 2;
            rev_code[i] = rev_code[i] % 2;
            rev_code[i - 1] += transfer;
        }
    if (rev_code[0] > 1)
        rev_code[0] = rev_code[0] % 2;

    memcpy(res, rev_code, arr_len);

       //int new_bin_num_len;// = sumNotAligned(rev_code, one, bin_num_len, sizeof (one), arr_len, res_arr_len, res);
    delete [] rev_code;
    return bin_num_len;
}

void printArr(const char *arr, const int print_len, std::ostream &out)
{
    out << (int) arr[0] << ".";
    for (int i = 1; i < print_len; i++)
        out << (int) arr[i];
}
}

void Binary1::print(std::ostream &out) const
{
    Bin1::printArr(this->bin_num, this->bin_num_len, out);
}

int Binary1::twosComplement(char *res, const int arr_len) const
{
    memset(res, 0, arr_len);
    int twos_num_len = Bin1::twosComplement(res, this->bin_num, this->bin_num_len, sizeof (this->bin_num));
    if (twos_num_len > arr_len)
        throw std::overflow_error("not enough length");
    return this->bin_num_len;
}

Binary1 &Binary1::add(const Binary1 &b)
{
    //int target_len = 0;
    //target_len = this->bin_num_len >= b.bin_num_len ? this->bin_num_len : b.bin_num_len;

    char _1[sizeof (this->bin_num)], _2[sizeof (this->bin_num)];
    char x[sizeof (this->bin_num)], y[sizeof (this->bin_num)];

    memcpy(&_1[2], &this->bin_num[1], this->bin_num_len - 1);
    memcpy(&_2[2], &b.bin_num[1], b.bin_num_len - 1);
    _1[1] = _2[1] = 0;
    _1[0] = this->bin_num[0];
    _2[0] = b.bin_num[0];

    const int arr_len = sizeof (this->bin_num);
    int a_num_len = this->bin_num_len + 1;
    int b_num_len = b.bin_num_len + 1;

    int target_bin_num_len = a_num_len >= b_num_len ? a_num_len : b_num_len;
    char a_aligned[arr_len], b_aligned[arr_len];
    memcpy(a_aligned, _1, arr_len);
    memcpy(b_aligned, _2, arr_len);
    Bin1::alignLen(a_aligned, target_bin_num_len, a_num_len, arr_len);
    Bin1::alignLen(b_aligned, target_bin_num_len, b_num_len, arr_len);

//    printf("_1: ");
//    printArr(a_aligned, target_bin_num_len, cout);
//    cout << "\n";
//    printf("_2: ");
//    printArr(b_aligned, target_bin_num_len, cout);
//    cout << "\n";

    Bin1::twosComplement(x, a_aligned, target_bin_num_len, sizeof (this->bin_num));
    Bin1::twosComplement(y, b_aligned, target_bin_num_len, sizeof (b.bin_num));

//    printf("x twos: ");
//    printArr(x, x_num_len, cout);
//    cout << "\n";
//    printf("y twos: ");
//    printArr(y, y_num_len, cout);
//    cout << "\n";

    char twos_res_num[sizeof (this->bin_num)];
    int twos_res_num_len = Bin1::sumAligned(x, y, target_bin_num_len, sizeof (this->bin_num), twos_res_num);
    this->bin_num_len = Bin1::twosComplement(this->bin_num, twos_res_num, twos_res_num_len, sizeof (twos_res_num));
    this->rmExtra0();
    return *this;
}

Binary1 &Binary1::preIncrement()
{
    this->add(Binary1(1));
    return *this;
}

const Binary1 Binary1::postDecrement()
{
    Binary1 x(*this);
    this->add(Binary1(-1));
    return x;
}

int Binary1::getSign() const
{
    if (this->bin_num[0] == 0)
        return 1;
    return -1;
}
