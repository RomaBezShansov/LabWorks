#include <stdlib.h>
#include <iostream>
int main()
{
    int i;
    i = 69;
    int number = 72;
    i = i + number;
    int array[3]{};   // 
    int* iPointer = &i;
    number = *iPointer;
    *iPointer = 15;
    iPointer = &array[0];
    int value1 = *iPointer; // 0
    iPointer = iPointer + 2;
    int value3 = *iPointer; // 3
    array[0] = 5;
    *iPointer = 6;
    array[1] = *iPointer;

    std::cout << value1 << ", " << value3 << std::endl;
    return 0;
}