#ifndef _STACK_LINKED_
#define _STACK_LINKED_

#include <stdexcept>

template <typename T>
class Stack {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* _top;

public:
	Stack() :_top(nullptr) {}

	~Stack() {
		while (!empty()) {
			pop();
		}
	}

	bool empty() const {
		return _top == nullptr;
	}

	void push(const T& data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = _top;
		_top = newNode;
	}

	void pop() {
		if (empty()) {
			throw std::underflow_error("Stack underflow error. Stack is empty.");
		}

		Node* tmp = _top;
		_top = _top->next;
		delete tmp;
	}

	T top() {
		if (empty()) {
			throw std::underflow_error("Stack underflow error. Stack is empty.");
		}

		return _top->data;
	}
};

#endif