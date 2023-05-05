#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

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
		arr = new T[_max_size];
	}

	~Array_Stack() {
		delete[] arr;
	}

	bool empty() {
		return _top == -1;
	}

	bool full() {
		return _top + 1 == _max_size;
	}

	int size() {
		return _top + 1;
	}

	int max_size() {
		return _max_size;
	}

	void push(T element) {
		arr[++_top] = element;
	}

	T pop() {
		return arr[_top--];
	}

	T top() {
		return arr[_top];
	}
};

#endif
