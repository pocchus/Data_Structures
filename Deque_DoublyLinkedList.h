#pragma once

class DequeUnderflow{};

class Deque {
private:
	struct DoublyLinkedNode {
		int data;
		DoublyLinkedNode* prev;
		DoublyLinkedNode* next;
	};
	DoublyLinkedNode* front;
	DoublyLinkedNode* back;

public:
	Deque() :front(nullptr), back(nullptr) {}
	~Deque();

	void push_back(int val);
	void push_front(int val);
	void pop_back();
	void pop_front();
	int peek_back();
	int peek_front();
};

Deque::~Deque() {
	DoublyLinkedNode* tmp;
	while (back != nullptr) {
		tmp = back;
		back = back->next;
		delete tmp;
	}
}

void Deque::push_back(int val) {
	if (back == nullptr) {
		front = back = new DoublyLinkedNode;
		back->data = val;
		back->prev = nullptr;
		back->next = nullptr;
	}
	else {
		DoublyLinkedNode* newback;
		newback->data = val;
		newback->next = back;
		newback->prev = nullptr;
		back->prev = newback;
		back = newback;
	}
}

void Deque::push_front(int val) {
	if (front == nullptr) {
		back = front = new DoublyLinkedNode;
		front->data = val;
		front->prev = nullptr;
		front->next = nullptr;
	}
	else {
		DoublyLinkedNode* newfront;
		newfront->data = val;
		newfront->next = nullptr;
		newfront->prev = front;
		front->next = newfront;
		front = newfront;
	}
}

void Deque::pop_back() {
	if (back == nullptr)
		throw DequeUnderflow();
	DoublyLinkedNode* tmp = back;
	back = back->next;
	back->prev = nullptr;
	delete tmp;
}

void Deque::pop_front() {
	if (front == nullptr)
		throw DequeUnderflow();
	DoublyLinkedNode* tmp = front;
	front = front->prev;
	front->next = nullptr;
	delete tmp;
}

int Deque::peek_back() {
	return back->data;
}

int Deque::peek_front() {
	return front->data;
}
