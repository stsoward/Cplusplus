#pragma once
#include "Stack.h"
using namespace std;

struct Node {
	int * data;
	Node * next;
};

class QueueLinkedList {
private:

	Node *head, *rear;
	int NumCards;
	int RoundsWon;
	Stack UserSideDeck;

public:

	QueueLinkedList();
	~QueueLinkedList();

	void insert(int * n);
	void deleteitem();
	int * Peek();
	int getNumCards();
	int getRoundsWon();
	void AddRoundWon();
	int getSideStackSize();
	int * SideStackPeek();
	void SideStackPop();
	void SideStackInsert(int * x);

};

QueueLinkedList::QueueLinkedList()
{
	head = nullptr;
	rear = nullptr;
	NumCards = 0;
	RoundsWon = 0;
}

QueueLinkedList :: ~QueueLinkedList()
{
	while (head != NULL)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	rear = NULL;
}

void QueueLinkedList::insert(int * n) {

	Node * temp = new Node;

	temp->data = n;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}

	NumCards++;
}

void QueueLinkedList::deleteitem() {

	if (head == rear) {
		head = nullptr;
		rear = nullptr;
	}
	else {
		head = head->next;
	}

	NumCards--;
}

int * QueueLinkedList::Peek() {
	return head->data;
}

int QueueLinkedList::getNumCards() {
	return NumCards + UserSideDeck.size();
}

int QueueLinkedList::getRoundsWon() {
	return RoundsWon;
}

void QueueLinkedList::AddRoundWon() {
	RoundsWon++;
}

int QueueLinkedList::getSideStackSize() {
	return UserSideDeck.size();
}

int * QueueLinkedList::SideStackPeek() {
	return UserSideDeck.peek();
}

void QueueLinkedList::SideStackPop() {
	UserSideDeck.pop();
}

void QueueLinkedList::SideStackInsert(int * x) {
	UserSideDeck.push(x);
}
