#include <iostream>
struct number
{
    int value;

    void operator+=(const number& param)
    {
        param.value += value;
    }
};
int main()
{
    number a{ 1 }, b{ 2 };
    a += b;
    std::cout << a.value << " " << b.value;
}