#ifndef UYOBISHE_RANDOMISE_HPP
#define UYOBISHE_RANDOMISE_HPP
#include <random>
#include <iostream>
#include <limits>
#include <vector>

#define BIG_NUMBER 100

float rand_float();

int menu();

void randomise_vector(std::vector<float>*vector, int N);

int len_vector(const std::vector<float>&vector);

void checkFloat_vector(std::vector<float>*selection, std::vector<float>vector);

class Randomise {
private:
    int len;
    std::vector<float> selection;
public:
    Randomise() : len(BIG_NUMBER), selection() { randomise_vector(&selection, BIG_NUMBER); };

    explicit Randomise(int n) : len(n), selection() { randomise_vector(&selection, n); };

    explicit Randomise(const std::vector<float>&vector) : len(len_vector(vector)), selection() { checkFloat_vector(&selection, vector); };

    void operator ++(int); // addNumber

    void refresh();

    void printRandomise();

//    void addNumber();

    float returnNumber(int index);

    float average();

    int getlen() const { return len; };

    void addTo(int quantity);

    std::vector<float> returnIn_Diapazon(float number1, float number2, std::vector<float> newselection);


};
namespace MyInput {
    template<class T>
    T getNum(std::istream &in = std::cin, std::ostream &out = std::cout) {
        T result;
        bool finished = false;
        while (!finished) {
            in >> result;
            if (in.bad() || in.eof()) {
                throw std::runtime_error("Wrong input");
            }
            if (!in.good()) {
                out << "Wrong input, please repeat" << std::endl;
                in.clear();
                std::string ignore;
                std::getline(in, ignore);
            } else {
                finished = true;
            }
        }
        return result;
    }
}

#endif //UYOBISHE_RANDOMISE_HPP
