#ifndef _STACK_ARRAY_
#define _STACK_ARRAY_

#include <stdexcept>

template <typename T>
class Stack
{
private:
    T *arr;
    size_t _top;
    size_t _capacity;
    void resize(size_t newCapacity);

public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T &data);
    void pop();
    T top();
};

#include "Stack_Array.cpp"

#endif