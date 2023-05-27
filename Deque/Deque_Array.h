#ifndef _DEQUE_ARRAY_
#define _DEQUE_ARRAY_

#include <stdexcept>

template <typename T>
class Deque
{
private:
    T *arr;
    size_t _front;
    size_t _back;
    size_t _size;
    size_t _capacity;
    void resize(size_t newCapacity);

public:
    Deque();
    Deque(size_t capacity);
    ~Deque();
    bool empty() const;
    size_t size() const;
    void push_back(const T &data);
    void push_front(const T &data);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
};

#include "Deque_Array.cpp"

#endif