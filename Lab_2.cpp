#include <string.h>
#include <iostream>

struct TwoInts //Обьявление структуры  которая группирует две переменные
{
    int a; // Подпеременные  
    int b;
};

struct StructWithArray
{
    int arr[4]; 
    int* someNumber; //Указатель 
};

int main()
{
    TwoInts i2 = { 5, 7 };
    i2.a = 5; //Вписать в подпеременные значения 5 и 7
    i2.b = 7;

    std::cout << i2.a << std::endl; //Выводит на экран 5 и 7
    std::cout << i2.b << std::endl;

    StructWithArray s = { 
        // {1,2,3,4},
        // &i2.a,
    };
    s.arr[0] = 10; // Первый элемент массива 10 

    StructWithArray s1 = { };
    s1.arr[1] = 15; // Второй элемент массива 15 

    StructWithArray* sPointer = &s; // Указатель sPointer на s
    sPointer->arr[0] = 20;// По указателю sPointer перейти на элемент массива 0 и вписывает 20

    (*sPointer).arr[0] = 20;


    std::cout << s.arr[0] << std::endl; //Выводит на экран указатель s со значением 20
    s.arr[0] = 25;

    std::cout << s.arr[0] << std::endl;
    sPointer->arr[0] = 30; // По указателю sPointer перейти на элемент массива 0 и вписывает 30
    std::cout << s.arr[0] << std::endl;

    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl;
    std::cout << s1.arr[0] << std::endl;

    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    structArray[1].someNumber = &structArray[0].arr[3];

    sPointer = &s;
    ((*sPointer).arr[3])=72;
    int* pointer = &((*sPointer).arr[3]);
    std::cout << *pointer;

    StructWithArray memory;
    memset(&memory, 0, sizeof(memory)); //Заполняет память переменной memory нулями
    return 0;
}