#include <iostream>

#pragma once
using namespace std;

class Stack
{
private:

	int *UserStack[5];
	int Top;
	int MaxSize;

public:

	Stack();
	void push(int * x);
	int * pop();
	int * peek();
	int size();
	bool isEmpty();
	bool isFull();
	void MakeEmpty();

	class OverFlow {};
	class UnderFlow {};

};

// Constructor
Stack::Stack() {

	MaxSize = 5;
	Top = -1;

}

// add an element x in the UserStack
void Stack::push(int * x) {
	if (isFull())
		throw OverFlow{};
	else
		UserStack[++Top] = x;
}


// removing Top element from the UserStack
int * Stack::pop() {
	if (isEmpty())
		throw UnderFlow{};
	else {
		UserStack[Top] = NULL;
		return UserStack[Top--];
	}
}

// return Top element in a Stack
int * Stack::peek() {
	if (!isEmpty())
		return UserStack[Top];
	else
		throw UnderFlow{};
}

// return size of the Stack
int Stack::size() {
	return Top + 1;
}

// test if UserStack is empty
bool Stack::isEmpty() {
	return Top == -1;
}

// test if UserStack is full
bool Stack::isFull() {
	return Top == 4;
}

void Stack::MakeEmpty() {
	delete[] UserStack;
}



