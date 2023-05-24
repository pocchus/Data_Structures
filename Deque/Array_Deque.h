#ifndef _ARRAY_DEQUE_
#define _ARRAY_DEQUE_

template <typename T>
class Array_Deque {
private:
	T* arr;
	int _front;
	int _back;
	int _max_size;
	int _size;
public:
	Array_Deque(int size) {
		_front = 0;
		_back = 0;
		_size = 0;
		_max_size = size + 1;
		arr = new T[_max_size];
	}

	~Array_Deque() {
		delete[] arr;
	}

	bool empty() {
		return _front == _back;
	}

	bool full() {
		return (_back + 1) % _max_size == front;
	}

	int size() {
		return _size;
	}

	void push_back(T element) {
		arr[_back] = element;
		_back = (_back + 1) % _max_size;
		_size++;
	}

	void push_front(T element) {
		_front = (_front + _max_size - 1) % _max_size;
		arr[_front] = element;
		_size++;
	}

	T pop_front() {
		T ret = arr[_front];
		_front = (_front + 1) % _max_size;
		_size--;
		return ret;
	}

	T pop_back() {
		_back = (_back + _max_size - 1) % _max_size;
		_size--;
		return arr[_back];
	}

	T front() {
		return arr[_front];
	}
};

#endif
