#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <iostream>
#include <new>

template <typename T>
class Array_Stack {
private:
	T* arr;
	int _top;
	int _max_size;
public:
	Array_Stack(int size) {
		_top = -1;
		_max_size = size;
		try {
			arr = new T[_max_size];
		}
		catch (std::bad_alloc& e) {
			std::cerr << "Allocation failed: " << e.what() << '\n';
			_max_size = 0;
		}
	}

	~Array_Stack() {
		delete[] arr;
	}

	bool empty() {
		return top == -1;
	}

	bool full() {
		return top + 1 == _max_size;
	}

	int size() {
		return top + 1;
	}

	int max_size() {
		return _max_size;
	}

	void push(T element) {
		arr[++top] = element;
	}

	T pop() {
		return arr[top--];
	}

	T top() {
		return arr[top];
	}
};

#endif
