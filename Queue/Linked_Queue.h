#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

template <typename T>
class Linked_Queue {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* _front;
	Node* _back;
	int _size;
public:
	Linked_Queue() {
		_front = nullptr;
		_back = nullptr;
		_size = 0;
	}

	~Linked_Queue() {
		Node* tmp;
		while (_front != nullptr) {
			tmp = _front;
			_front = _front->next;
			delete tmp;
		}
	}

	bool empty() {
		return !_front;
	}

	int size() {
		return _size;
	}

	void push(T element) {
		Node* newNode = new Node;
		newNode->data = element;
		newNode->next = nullptr;
		if (!_back) {
			_back = newNode;
			_front = _back;
		}
		else {
			_back->next = newNode;
			_back = newNode;
		}
		_size++;
	}

	T pop() {
		T ret = _front->data;
		Node* tmp = _front;
		_front = _front->next;
		delete tmp;
		if (!_front) {
			_back = nullptr;
		}
		_size--;
		return ret;
	}

	T front() {
		return _front->data;
	}
};

#endif
