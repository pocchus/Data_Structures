#ifndef _QUEUE_LINKED_
#define _QUEUE_LINKED_

template <typename T>
class Queue {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* _front;
	Node* _back;

public:
	Queue() :_front(nullptr), _back(nullptr){}

	~Queue() {
		while (!empty()){
			pop();
		}
	}

	bool empty() const {
		return _front == nullptr;
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
	}

	void pop() {
		if (empty()) {
			throw std::underflow_error("Stack underflow error. Stack is empty.");
		}

		Node* tmp = _front;
		_front = _front->next;
		delete tmp;

		if (_front == nullptr) {
			_back = nullptr;
		}
	}

	T front() {
		if (empty()) {
			throw std::underflow_error("Stack underflow error. Stack is empty.");
		}

		return _front->data;
	}
};

#endif
