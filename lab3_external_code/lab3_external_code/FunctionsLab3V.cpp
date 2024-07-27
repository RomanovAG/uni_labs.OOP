#include "randomiseV.hpp"

void randomise_vector(std::vector<float>*vector, int N) {
    for (int i = 0; i < N; i++)
        (*vector).push_back(rand_float());
}

int len_vector(const std::vector<float>&vector) {
    return static_cast<int> (vector.size());
}

void checkFloat_vector(std::vector<float>*selection, std::vector<float>vector) {
    for (int i = 0; i < len_vector(vector); i++) {
        if (vector[i] < 0.0 || vector[i] > 1.0)
            vector[i] = rand_float();
        (*selection).push_back(vector[i]);
    }
}

int menu() {
    std::cout << "Enter your choice:" << std::endl;
    std::cout << "[1] Refresh selection" << std::endl;
    std::cout << "[2] Print selection" << std::endl;
    std::cout << "[3] Add new random number" << std::endl;
    std::cout << "[4] Return a random number by index " << std::endl;
    std::cout << "[5] Return the arithmetic mean of the selection" << std::endl;
    std::cout << "[6] Operation \"Add to\" " << std::endl;
    std::cout << "[7] Return a selection in the range " << std::endl;
    std::cout << "[8] Exit" << std::endl;
    return MyInput::getNum<int>();
}

void Randomise::refresh() {
    for (int i = 0; i < len; i++)
        selection[i] = rand_float();
}

void Randomise::printRandomise() {
    for (int i = 0; i < len; i++)
        std::cout << selection[i] << std::endl;
}


//void Randomise::addNumber() {
//    selection[len] = rand_float();
//    ++len;
//}


float Randomise::returnNumber(int index) {
    return selection[index];
}


float Randomise::average() {
    float s = 0.0;
    for (int i = 0; i < len; i++) {
        s = s + selection[i];
    }
    return s / (float) len;

}

void Randomise::addTo(int quantity) {
    while (len < quantity) {
        selection.push_back(rand_float());
        ++len;
    }
}

float rand_float() {
    return (float) rand() / (float) RAND_MAX;
}

std::vector<float> Randomise::returnIn_Diapazon(float number1, float number2, std::vector<float> newselection) {
    for (int i = 0; i < len; i++)
        if (selection[i] > number1 && selection[i] < number2)
            newselection.push_back(selection[i]);
    return newselection;
}

void Randomise::operator++(int){
    selection[len] = rand_float();
    ++len;
}








