#ifndef _QUEUE_LINKED_
#define _QUEUE_LINKED_

#include <stdexcept>

template <typename T>
class Queue {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* _front;
	Node* _back;
	size_t _size;

public:
	Queue() :_front(nullptr), _back(nullptr), _size(0) {}

	~Queue() {
		while (!empty()) {
			pop();
		}
	}

	bool empty() const {
		return _front == nullptr;
	}

	size_t size() {
		return _size;
	}

	void push(const T& data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (empty()) {
			_back = newNode;
			_front = _back;
		}
		else {
			_back->next = newNode;
			_back = newNode;
		}
		_size++;
	}

	void pop() {
		if (empty()) {
			throw std::underflow_error("Queue is empty.");
		}

		Node* tmp = _front;
		_front = _front->next;
		delete tmp;
		if (_front == nullptr) {
			_back = nullptr;
		}
		_size--;
	}

	T front() {
		if (empty()) {
			throw std::underflow_error("Queue is empty.");
		}
		return _front->data;
	}
};

#endif