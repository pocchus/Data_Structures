#ifndef _LINKED_STACK_
#define _LINKED_STACK_

template <typename T>
class Linked_Stack {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* _top;
	int _size;
public:
	Linked_Stack() {
		_top = nullptr;
		_size = 0;
	}

	~Linked_Stack() {
		Node* tmp;
		while (_top != nullptr) {
			tmp = _top;
			_top = _top->next;
			delete tmp;
		}
	}

	bool empty() {
		return !_top;
	}

	int size() {
		return _size;
	}

	void push(T element) {
		Node* newNode;
		newNode = new Node;
		newNode->data = element;
		newNode->next = _top;
		_top = newNode;
		_size++;
	}

	T pop() {
		T ret = _top->data;
		Node* tmp = _top;
		_top = _top->next;
		delete tmp;
		_size--;
		return ret;
	}

	T top() {
		return _top->data;
	}
};

#endif
