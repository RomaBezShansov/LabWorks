#include <iostream>
#include <cstddef>
#include <array>
#include <span>

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
    int inputOutput[] = { 1,2,3,4 };
    int coefficients[] = { 1,2,3,4 };
    product(inputOutput, coefficients);

}