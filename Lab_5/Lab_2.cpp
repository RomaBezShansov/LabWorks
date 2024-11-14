#include <iostream>     
#include <span>

using namespace std;

int count(std::span<char> str)
{
    int s = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
       if (str[i] == '1') //ASCII ���
       {
           s += 1;
       }

    }
    return s;
}


int main() 
{
    char str[] = { "He11o wor1d" };
    int s = count(str);
    std::cout << s << std::endl;
}