#ifndef _STACK_LINKED_
#define _STACK_LINKED_

#include <stdexcept>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *_top;
    size_t _size;

public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size();
    void push(const T &data);
    void pop();
    T top();
};

#include "Stack_Linked.cpp"

#endif