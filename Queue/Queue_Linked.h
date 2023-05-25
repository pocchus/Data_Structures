#ifndef _QUEUE_LINKED_
#define _QUEUE_LINKED_

#include <stdexcept>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *_front;
    Node *_back;
    size_t _size;

public:
    Queue();
    ~Queue();
    bool empty() const;
    size_t size();
    void push(const T &data);
    void pop();
    T front();
};

#include "Queue.cpp"

#endif