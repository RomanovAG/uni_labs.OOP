#include <iostream>

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

int getDouble(double *value)
{
    double temp;
    std::cin >> temp;
    if (std::cin.fail())
    {
        std::cin.clear();
        return -1;
    }
    *value = temp;
    return 0;
}
