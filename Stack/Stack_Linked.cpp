#include "Stack_Linked.h"

template <typename T>
Stack<T>::Stack() : _top(nullptr), _size(0) {}

template <typename T>
Stack<T>::~Stack()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
bool Stack<T>::empty() const
{
    return _top == nullptr;
}

template <typename T>
size_t Stack<T>::size() const
{
    return _size;
}

template <typename T>
void Stack<T>::push(const T &data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = _top;
    _top = newNode;
    _size++;
}

template <typename T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Stack is empty.");
    }

    Node *tmp = _top;
    _top = _top->next;
    delete tmp;
    _size--;
}

template <typename T>
T Stack<T>::top() const
{
    if (empty())
    {
        throw std::underflow_error("Stack is empty.");
    }

    return _top->data;
}