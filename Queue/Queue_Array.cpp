#include "Queue_Array.h"

template <typename T>
void Queue<T>::resize(size_t newCapacity)
{
    T *newArr = new T[newCapacity];
    for (size_t i = 0; i < _size; i++)
    {
        newArr[i] = arr[(_front + i) % _capacity];
    }
    delete[] arr;
    arr = newArr;
    _capacity = newCapacity;
    _front = 0;
    _back = _size;
}

template <typename T>
Queue<T>::Queue() : _front(0), _back(0), _size(0), _capacity(2)
{
    arr = new T[_capacity];
}

template <typename T>
Queue<T>::Queue(size_t capacity) : _front(0), _back(0), _size(0), _capacity(capacity)
{
    arr = new T[_capacity];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template <typename T>
bool Queue<T>::empty() const
{
    return _size == 0;
}

template <typename T>
size_t Queue<T>::size() const
{
    return _size;
}

template <typename T>
void Queue<T>::push(const T &data)
{
    if (_size == _capacity)
    {
        size_t newCapacity = _capacity * 2;
        resize(newCapacity);
    }
    arr[_back] = data;
    _back = (_back + 1) % _capacity;
    _size++;
}

template <typename T>
void Queue<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Queue is empty.");
    }
    _front = (_front + 1) % _capacity;
    if (_size < _capacity / 4 && _capacity > 2)
    {
        size_t newCapacity = _capacity / 2;
        resize(newCapacity);
    }
    _size--;
}

template <typename T>
T Queue<T>::front()
{
    if (empty())
    {
        throw std::underflow_error("Queue is empty.");
    }
    return arr[_front];
}