```cpp
// Файл HeapInt.h
#pragma once // 1
#include <cassert>

class HeapInt
{
private:
    int* heapValue; // 2

public:
    // 3
    inline HeapInt(int val) // : heapValue(val)
    {
    heapValue = val;
    }
        // 4
        : heapValue(new int{ val })
    {
    }

    inline ~HeapInt()
    {
        // Заметка: delete проверяет на nullptr сам.
        delete heapValue; // 5
    }

    inline int& asRef()
    {
        assert(heapValue != nullptr); // 6
        return *heapValue;
    }

    HeapInt(const HeapInt& hello); // 7 Конструктор копирования
    HeapInt(HeapInt&& hello);
    void operator=(const HeapInt& hello);
    void operator=(HeapInt&& hello);
};

// Файл main.cpp
#include "HeapInt.h"

void constructors()
{
    HeapInt a{5}; // 8 
    HeapInt b{a}; // 9
    HeapInt c{std::move(a)}; // 10
    HeapInt d = b; // 11
    HeapInt e = std::move(b); // 12
    d = std::move(c); // 13
    d = e; // 14
    d.operator=(e);
}

// Файл HeapInt.cpp
#include "HeapInt.h"

// ... 15
```

Дан класс HeapInt выше, представляющий собой обертку для динамически выделенного инта. В отличии от обычного int*, этот тип не позволяет nullptr как валидное значение.

Класс следует RAII, выделяя память в конструкторе, и удаляя ее в деструкторе.

1) Почему поле heapValue (2) приватное?

Параметр Private встроеный в класс и его не надо писать.

2) Что означает этот синтаксис (4)? Как его расписать в теле конструктора?
```cpp
 inline HeapInt(int val) // : heapValue(val)
    {
    heapValue = val;
    }

     inline HeapInt(int val) : heapValue(val)
    {
    
    }

    inline HeapInt(int val) : heapValue(new int{ val }){} //Этот конструктор выделяет память на куче для целого числа и инициализирует указатель heapValue значением, которое передается в конструктор.
```

Как скомпилировать это с помощью GCC?

g++ -c HeapInt.cpp -Werror -Wall -Wextra -Wconversion -std=c++20
g++ -c main.cpp -Werror -Wall -Wextra -Wconversion -std=c++20
g++ -c HeapInt.o main.o -Werror -Wall -Wextra -Wconversion -std=c++20




Зачем (1)? Какую ситуацию это предотвратит? 

Эта директива препроцессора указывает компилятору, что файл должен быть включен только один раз при компиляции. Это предотвращает множественные включения одного и того же заголовочного файла. 


Почему (3) определена как inline?

Он вставляет копию текста функции в каждое место, где вызывается функция.


Как можно обойти ограничение, что конструктор или функция должны быть inline?
Оставить только прототип\обьявление
inline HeapInt(int val)

А реализовать\определить в cpp
HeapInt::HeapInt(int val) : heapValue(new int{ val }){} 

Зачем на (6) нужна проверка, если int* не может быть nullptr?

Нулевые указатели полезны для предотвращения ошибок, связанных с доступом к неинициализированной памяти, что может привести к непредсказуемому поведению программы или её краху.


Объясните, какой из конструкторов или перегруженных операторов вызовется для (8-14). Какие из них эквивалентны?
```cpp
    HeapInt a{5}; // 8 Конструктор HeapInt(int val)
    HeapInt b{a}; // 9 Констурктор копирования  HeapInt(const HeapInt& hello);
    HeapInt c{std::move(a)}; // 10 Конструктор перемещения 
    HeapInt d = b; // 11 Копирование
    HeapInt e = std::move(b); // 12 Перемещение

Как запретить синтаксис на (11-12)?
Удалить соответсвующие конструкторы 

    HeapInt(const HeapInt& hello); // 7 Конструктор копирования
    HeapInt(HeapInt&& hello); // Конструктор перемещения
```
Определите на (15) конструкторы и операторы на (7).

Как определить конструктор или перегруженный оператор отдельно?
А что в них делать?
В какой еще ситуации вызовется rvalue reference перегрузка конструктора или оператора присваивания?

Перегрузка?

Сколько раз вызовется деструктор для типа HeapInt после (14)?


Объясните, какая по вашему мнению была мотивация того, что у этого типа не был определен дефолтный конструктор?



Объясните, почему считывать значение объекта после применения std::move это неправильная операция?


Создайте функцию void swap(HeapInt& a, HeapInt& b), которая меняет значения, без выделения новой динамической памяти.