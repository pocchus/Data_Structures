#pragma once

class StackUnderflow {};

class Stack {
private:
	struct SinglyLinkedNode {
		int data;
		SinglyLinkedNode* next;
	};
	SinglyLinkedNode* top;
public:
	Stack() :top(nullptr) {}
	~Stack();

	void push(int val);
	bool empty();
	int peek();
	void pop();
};

Stack::~Stack() {
	SinglyLinkedNode* tmp;
	while (top != nullptr) {
		tmp = top;
		top = top->next;
		delete tmp;
	}
}

void Stack::push(int val) {
	SinglyLinkedNode* newtop = new SinglyLinkedNode;
	newtop->data = val;
	newtop->next = top;
	top = newtop;
}

bool Stack::empty() {
	if (top == nullptr)
		return true;
	else
		return false;
}

int Stack::peek() {
	if (empty())
		throw StackUnderflow();
	return top->data;
}

void Stack::pop() {
	if (empty())
		throw StackUnderflow();
	SinglyLinkedNode* tmp = top;
	top = top->next;
	delete tmp;
}
