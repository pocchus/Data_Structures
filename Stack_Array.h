#pragma once

class StackOverflow {};
class StackUnderflow {};

class Stack {
private:
	int* arr;
	int top;
	int maxsize;
public:
	Stack(int size) :maxsize(size), top(-1), arr(new int[size]) {}
	~Stack();

	void push(int val);
	bool empty();
	int peek();
	void pop();
};

Stack::~Stack() {
	delete[] arr;
}

void Stack::push(int val) {
	if (top + 1 >= maxsize)
		throw StackOverflow();
	arr[++top] = val;
}

bool Stack::empty() {
	if (top < 0)
		return true;
	else
		return false;
}

int Stack::peek() {
	if (empty())
		throw StackUnderflow();
	else
		return arr[top];
}

void Stack::pop() {
	if (empty())
		throw StackUnderflow();
	else
		top--;
}
