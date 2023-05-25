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

    void resize(size_t newCapacity)
    {
        T *newArr = new T[newCapacity];
        for (size_t i = 0; i < _top; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        _capacity = newCapacity;
    }

public:
    Stack() : _capacity(4), _top(0)
    {
        arr = new T[_capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool empty() const
    {
        return _top == 0;
    }

    size_t size() const
    {
        return _top;
    }

    void push(const T &data)
    {
        if (_top == _capacity)
        {
            size_t newCapacity = _capacity * 2;
            resize(newCapacity);
        }
        arr[_top++] = data;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        _top--;
        if (_top < _capacity / 4 && _capacity > 4)
        {
            size_t newCapacity = _capacity / 2;
            resize(newCapacity);
        }
    }

    T top()
    {
        if (empty())
        {
            throw std::underflow_error("Stack is empty.");
        }
        return arr[_top - 1];
    }
};

#endif