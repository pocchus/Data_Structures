#ifndef _STACK_ARRAY_
#define _STACK_ARRAY_

#include <stdexcept>

template <typename T>
class Stack {
private:
    T* arr;
    size_t _top;
    size_t _capacity;

    void resize(size_t newCapacity) {
        T* newArr = new T[newCapacity];
        for (size_t i = 0; i < top; i++) {
            newArr[i] = arr[i];
        }
        delete arr;
        arr = newArr;
        _capacity = newCapacity;
    }

public:
    Stack() : _capacity(2), _top(0) {
        arr = new T[_capacity];
    }

    ~Stack() {
        delete arr;
    }

    bool empty() const {
        return top == 0;
    }

    size_t size() {
        return _top;
    }

    void push(const T& data) {
        if (top == _capacity) {
            size_t newCapacity = capacity * 2;
            resize(newCapacity);
        }
        arr[top++] = data;
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty.");
        }
        top--;
    }

    T top() {
        if (empty()) {
            throw std::underflow_error("Stack is empty.");
        }
        return data[top - 1];
    }
};

#endif