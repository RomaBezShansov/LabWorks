#include "HeapInt.h"


HeapInt::HeapInt(const HeapInt& other)
    : heapValue(new int{ *other.heapValue })
{
}

HeapInt::HeapInt(HeapInt&& other) noexcept
    : heapValue(other.heapValue)
{
    other.heapValue = nullptr;
}

void HeapInt::operator=(const HeapInt& hello)
{
    
}