#ifndef _QUEUE_ARRAY_
#define _QUEUE_ARRAY_

#include <stdexcept>

template <typename T>
class Queue
{
private:
    T *arr;
    size_t _front;
    size_t _back;
    size_t _size;
    size_t _capacity;
    void resize(size_t newCapacity);

public:
    Queue();
    Queue(size_t capacity);
    ~Queue();
    bool empty() const;
    size_t size() const;
    void push(const T &data);
    void pop();
    T front();
};

#include "Queue_Array.cpp"

#endif