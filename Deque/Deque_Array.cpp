#include "Deque_Array.h"

template <typename T>
void Deque<T>::resize(size_t newCapacity)
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
Deque<T>::Deque() : _front(0), _back(0), _size(0), _capacity(2)
{
    arr = new T[_capacity];
}

template <typename T>
Deque<T>::Deque(size_t capacity) : _front(0), _back(0), _size(0), _capacity(capacity)
{
    arr = new T[_capacity];
}

template <typename T>
Deque<T>::~Deque()
{
    delete[] arr;
}

template <typename T>
bool Deque<T>::empty() const
{
    return _size == 0;
}

template <typename T>
size_t Deque<T>::size() const
{
    return _size;
}

template <typename T>
void Deque<T>::push_back(const T &data)
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
void Deque<T>::push_front(const T &data)
{
    if (_size == _capacity)
    {
        size_t newCapacity = _capacity * 2;
        resize(newCapacity);
    }
    _front = (_front + _capacity - 1) % _capacity;
    arr[_front] = data;
    _size++;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
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
void Deque<T>::pop_back()
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }
    _back = (_back + _capacity - 1) % _capacity;
    if (_size < _capacity / 4 && _capacity > 2)
    {
        size_t newCapacity = _capacity / 2;
        resize(newCapacity);
    }
    _size--;
}

template <typename T>
T Deque<T>::front() const
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }
    return arr[_front];
}

template <typename T>
T Deque<T>::back() const
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }
    return arr[(_back + 1) % _capacity];
}