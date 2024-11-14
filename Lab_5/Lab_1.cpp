#include <iostream>     
#include <span>

using namespace std;

string_view SecondWord(std::span<char> str)
{
    int s = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ') 
        {
            s = i + 1;
            break;
        }
        
        
    }
    string_view second_word{ &str[s], str.size() - s };
    return second_word;
}


int main()
{
    char str[] = { "He11o wor1d" };
    string_view s = SecondWord(str);
    std::cout << s << std::endl;
}