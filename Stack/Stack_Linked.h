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
	Stack() : _top(nullptr), _size(0) {}

	~Stack()
	{
		while (!empty())
		{
			pop();
		}
	}

	bool empty() const
	{
		return _top == nullptr;
	}

	size_t size()
	{
		return _size;
	}

	void push(const T &data)
	{
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = _top;
		_top = newNode;
		_size++;
	}

	void pop()
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

	T top()
	{
		if (empty())
		{
			throw std::underflow_error("Stack is empty.");
		}

		return _top->data;
	}
};

#endif