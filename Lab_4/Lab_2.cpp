#include <iostream>

int main()
{
    struct fruits {

        int apples;
        int pears;
        int oranges;
    };

    fruits f;

    std::cout << "Apples:";
    std::cin >> f.apples;

    std::cout << "Pears:";
    std::cin >> f.pears;

    std::cout << "Oranges:";
    std::cin >> f.oranges;

    bool t;
    {
    bool applesTrue = f.apples > 5;
    bool pearsTrue = f.pears < 8;
    bool orangesTrue = f.oranges > f.apples * 2;
    t = applesTrue && pearsTrue && orangesTrue;
    }

    //if (apples > 5 && pears < 8 && oranges > apples * 2)
    //if (applesTrue && pearsTrue && orangesTrue)
    if(t)
    {
        std::cout << "Hello" << std::endl;
        
    }
    return 0;
}