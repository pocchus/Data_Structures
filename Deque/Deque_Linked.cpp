#include "Deque_Linked.h"

template <typename T>
Deque<T>::Deque() : _front(nullptr), _back(nullptr), _size(0) {}

template <typename T>
Deque<T>::~Deque()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
bool Deque<T>::empty() const
{
    return _front == nullptr;
}

template <typename T>
size_t Deque<T>::size() const
{
    return _size;
}

template <typename T>
void Deque<T>::push_front(const T &data)
{
    Node *newNode = new Node(data);
    if (empty())
    {
        _front = newNode;
        _back = newNode;
    }
    else
    {
        newNode->prev = _front;
        _front->next = newNode;
        _front = newNode;
    }
    _size++;
}

template <typename T>
void Deque<T>::push_back(const T &data)
{
    Node *newNode = new Node(data);
    if (empty())
    {
        _front = newNode;
        _back = newNode;
    }
    else
    {
        newNode->next = _back;
        _back->prev = newNode;
        _back = newNode;
    }
    _size++;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }

    Node *tmp = _front;
    if (_front == _back)
    {
        _front = nullptr;
        _back = nullptr;
    }
    else
    {
        _front = _front->prev;
        _front->next = nullptr;
    }
    delete tmp;
    _size--;
}

template <typename T>
void Deque<T>::pop_back()
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }

    Node *tmp = _back;
    if (_front == _back)
    {
        _front = nullptr;
        _back = nullptr;
    }
    else
    {
        _back = _back->next;
        _back->prev = nullptr;
    }
    delete tmp;
    _size--;
}

template <typename T>
T Deque<T>::front() const
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }
    return _front->data;
}

template <typename T>
T Deque<T>::back() const
{
    if (empty())
    {
        throw std::underflow_error("Deque is empty.");
    }
    return _back->data;
}