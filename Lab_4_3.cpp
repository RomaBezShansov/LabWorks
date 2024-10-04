#include <iostream>
#include <cstddef>
#include <array>
#include <span>

void product(std::span<int> inputOutput, std::span<int> coefficients)
{
    for (size_t index = 0; index < inputOutput.size(); index++)
    {
        int result = inputOutput[index] * coefficients[index];
        int result = InputOutput[index];
    }
    std::cout << InputOutput[0] << std::endl;
    std::cout << InputOutput[1] << std::endl;
    std::cout << InputOutput[2] << std::endl;
    std::cout << InputOutput[3] << std::endl;
}


int main()
{
    int inputOutput[4] = { 2,4,6,8 };
    int coefficients[4] = { 2,4,6,8 };
    
    
    product(inputOutput, coefficients);

}
