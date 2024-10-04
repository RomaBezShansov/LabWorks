#include <iostream>

void testAndPrint(int number)
{
    //guard clause
    if (number == 5)
    {
        std::cout << "The number is 5" << std::endl;
        //early return
        return;
    }
    std::cout << "The number is not 5" << std::endl;

    if (number % 2 == 1)
    {
        std::cout << "The number is not divisible by 2" << std::endl;
        return;
    }
    std::cout << "The number is divisible by 2" << std::endl;
    if (number == 6)
    {
        std::cout << "The number is 6" << std::endl;
        return;
    }
    std::cout << "The number is not 6" << std::endl;
}

int main()
{
    int number = 6;

    testAndPrint(number);
}