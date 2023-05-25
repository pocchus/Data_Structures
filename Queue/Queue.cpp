#include "Queue_Linked.h"

template <typename T>
Queue<T>::Queue() : _front(nullptr), _back(nullptr), _size(0) {}

template <typename T>
Queue<T>::~Queue()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
bool Queue<T>::empty() const
{
    return _front == nullptr;
}

template <typename T>
size_t Queue<T>::size()
{
    return _size;
}

template <typename T>
void Queue<T>::push(const T &data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (empty())
    {
        _back = newNode;
        _front = _back;
    }
    else
    {
        _back->next = newNode;
        _back = newNode;
    }
    _size++;
}

template <typename T>
void Queue<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Queue is empty.");
    }

    Node *tmp = _front;
    _front = _front->next;
    delete tmp;
    if (_front == nullptr)
    {
        _back = nullptr;
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
    return _front->data;
}