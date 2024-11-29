#pragma once // 1
#include <cassert>

class HeapInt
{
    int* heapValue; // 2

public:
    // 3
    inline HeapInt(int val) : heapValue(new int{ val }){} 

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

    HeapInt(const HeapInt& hello); // 7
    HeapInt(HeapInt&& hello);
    void operator=(const HeapInt& hello);
    void operator=(HeapInt&& hello);
};


