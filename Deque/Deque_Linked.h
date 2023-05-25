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
    Deque() : _front(nullptr), _back(nullptr), _size(0) {}

    ~Deque()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    bool empty() const
    {
        return _front == nullptr;
    }

    size_t size() const
    {
        return _size;
    }

    void push_front(const T &data)
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

    void push_back(const T &data)
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

    void pop_front()
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

    void pop_back()
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

    T front() const
    {
        if (empty())
        {
            throw std::underflow_error("Deque is empty.");
        }
        return _front->data;
    }

    T back() const
    {
        if (empty())
        {
            throw std::underflow_error("Deque is empty.");
        }
        return _back->data;
    }
};

#endif