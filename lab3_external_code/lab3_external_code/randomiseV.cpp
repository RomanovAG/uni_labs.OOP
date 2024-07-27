#include "randomiseV.hpp"


int main() {
    srand(time(nullptr));
    Randomise r(5);

    do {
        int choice = menu();
        switch (choice) {
            case 1: {
                r.refresh();
                std::cout << "Vector refreshed" << std::endl;
                break;
            }
            case 2: {
                r.printRandomise();
                break;
            }
            case 3: {
                r++;
                std::cout << "Number added" << std::endl;
                break;
            }
            case 4: {
                int index;
                do {
                    std::cout << "Enter index" << std::endl;
                    index = MyInput::getNum<int>();
                    if (index < 0 || index >= r.getlen())
                        std::cout << "Index error, try again" << std::endl;
                } while (index < 0 || index >= r.getlen());
                std::cout << r.returnNumber(index) << std::endl;
                break;
            }
            case 5: {
                std::cout << "The arithmetic mean of the selection is " << r.average() << std::endl;
                break;
            }
            case 6: {
                std::cout << "Enter number of numbers" << std::endl;
                int quantity;
                do {
                    quantity = MyInput::getNum<int>();
                    if (quantity < r.getlen())
                        std::cout << "Quantity error, try again" << std::endl;
                } while (quantity < r.getlen());
                r.addTo(quantity);
                std::cout << "Numbers added" << std::endl;
                break;
            }
            case 7: {
                float number1;
                float number2;
                do {
                    std::cout << "Enter first float number" << std::endl;
                    number1 = MyInput::getNum<float>();
                    std::cout << "Enter second float number" << std::endl;
                    number2 = MyInput::getNum<float>();
                    if (number1 >= number2)
                        std::cout << "Error, try again" << std::endl;
                } while (number1 >= number2);
                std::vector<float> newselection;
                Randomise R(r.returnIn_Diapazon(number1, number2, newselection));
                R.printRandomise();
                break;
            }
            case 8: {
                return 0;
            }

            default: {
                std::cout << "Wrong input, please try again" << std::endl;
            }
        }
    } while (true);
}
