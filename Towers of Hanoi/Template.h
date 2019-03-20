#include <iostream>
#include "Disks.h"

#pragma once
using namespace std;

// define default SIZE of Stack
#define SIZE 10

// Class for Stack
template <class T>
class Stack
{
private:
	T *UserStack;
	int Top;
	int MaxSize;
	friend void printArray(Stack <Disks> s1, Stack <Disks> s2, Stack <Disks> s3, Stack <Disks> s4, Stack <Disks> s5);
public:
	Stack(int s = SIZE);
	void push(T * x);
	T * pop();
	T * peek();
	int size();
	bool isEmpty();
	bool isFull();
	void Empty();
	bool Win();

	class OverFlow {};
	class UnderFlow {};

};

// Constructor
template <class T>
Stack<T>::Stack(int s) {
	UserStack = new T[s];
	MaxSize = s;
	Top = -1;


}

// add an element x in the UserStack
template<class T>
void Stack<T>::push(T * x)
{
	if (isFull())
		throw OverFlow{};
	else
		UserStack[++Top] = *x;
}


// removing Top element from the UserStack
template <class T>
T * Stack<T>::pop() {
	if (isEmpty())
		throw UnderFlow{};
	else {
		UserStack[Top].setSize(NULL);
		return &UserStack[Top--];
	}
}

// return Top element in a Stack
template <class T>
T * Stack<T>::peek() {
	if (!isEmpty())
		return &UserStack[Top];
	else
		throw UnderFlow{};
}

// return size of the Stack
template <class T>
int Stack<T>::size() {
	return Top + 1;
}

// test if UserStack is empty
template <class T>
bool Stack<T>::isEmpty() {
	return Top == -1;
}

// test if UserStack is full
template <class T>
bool Stack<T>::isFull() {
	return Top == MaxSize - 1;
}

template <class T>
void Stack<T>::Empty() {
	delete[] UserStack;
}

template <class Disks>
bool Stack<Disks>::Win() {
	for (int i = 1; i <= MaxSize; i++) {
		if (!(UserStack[MaxSize - i].getSize() == i))
			return false;
	}
	return true;
}

