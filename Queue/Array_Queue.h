#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

template <typename T>
class Array_Queue {
private:
	T* arr;
	int _front;
	int _back;
	int _max_size;
	int _size;
public:
	Array_Queue(int size) {
		_front = 0;
		_back = 0;
		_size = 0;
		_max_size = size + 1;
		arr = new T[_max_size];
	}

	~Array_Queue() {
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

	void push(T element) {
		arr[_back] = element;
		_back = (_back + 1) % _max_size;
		_size++;
	}

	T pop() {
		T ret = arr[_front];
		_front = (_front + 1) % _max_size;
		_size--;
		return ret;
	}

	T front() {
		return arr[_front];
	}
};

#endif
