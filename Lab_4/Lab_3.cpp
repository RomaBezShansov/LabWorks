#include <iostream>
#include <cstddef>
#include <array>
#include <span>


int product(int* inputOutput, int coefficients[], size_t size)
{
}

int product(std::span<int> inputOutput, std::span<int> coefficients)
{
    for (size_t i = 0; i < coefficients.size(); i++)
    {
        inputOutput[i] *= coefficients[i];
        
    }
    return 0;
}


int main()
{
    int inputOutput[4] = { 1,2,3,4 };
    int coefficients[4] = { 1,2,3,4 };
    std::span<int> a = {1,2,3,4};
    int* a = inputOutput;
    int* b = coefficients;
    product(inputOutput, b);

}