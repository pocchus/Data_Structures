#include "Stack_Array.h"

template <typename T>
void Stack<T>::resize(size_t newCapacity)
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

template <typename T>
Stack<T>::Stack() : _capacity(2), _top(0)
{
    arr = new T[_capacity];
}

template <typename T>
Stack<T>::Stack(size_t capacity) : _capacity(capacity), _top(0)
{
    arr = new T[_capacity];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template <typename T>
bool Stack<T>::empty() const
{
    return _top == 0;
}

template <typename T>
size_t Stack<T>::size() const
{
    return _top;
}

template <typename T>
void Stack<T>::push(const T &data)
{
    if (_top == _capacity)
    {
        size_t newCapacity = _capacity * 2;
        resize(newCapacity);
    }
    arr[_top++] = data;
}

template <typename T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    _top--;
    if (_top < _capacity / 4 && _capacity > 2)
    {
        size_t newCapacity = _capacity / 2;
        resize(newCapacity);
    }
}

template <typename T>
T Stack<T>::top() const
{
    if (empty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    return arr[_top - 1];
}