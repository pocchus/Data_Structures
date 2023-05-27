#ifndef _DEQUE_LINKED_
#define _DEQUE_LINKED_

#include <stdexcept>

template <typename T>
class Deque
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
        Node(const T &_data) : data(_data), prev(nullptr), next(nullptr) {}
    };
    Node *_front;
    Node *_back;
    size_t _size;

public:
    Deque();
    ~Deque();
    bool empty() const;
    size_t size() const;
    void push_front(const T &data);
    void push_back(const T &data);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
};

#include "Deque_Linked.cpp"

#endif