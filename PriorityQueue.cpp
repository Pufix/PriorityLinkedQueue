#include "PriorityQueue.h"
#include <exception>
using namespace std;


PriorityQueue::PriorityQueue(Relation r) {
	//TODO - Implementation
	elems = NULL;
	size = 0;
	rel = r;
}


void PriorityQueue::push(TElem e, TPriority p) {
	// time complexity O(n)
	Node *newNode = new Node;
	newNode->info = make_pair(e, p);
	newNode->next = NULL;
	// if the queue is empty then add in the first position
	if (isEmpty()) {
		elems = newNode;
		size++;
		return;
	}
	// we iterate through the queue until we find the position where we can add the new element
	Node *aux = elems;
	while (aux->next != NULL&& rel(aux->next->info.second,p)) {
		aux = aux->next;
	}
	// if the new element has higher prio than the current element then we swap them
	if (!rel(aux->info.second, p)) {
		swap(aux->info, newNode->info);
		newNode->next = aux->next;
		aux->next = newNode;
		size++;
		return;
	}
	newNode->next = aux->next;
	aux->next = newNode;
	size++;
	return;
}

//throws exception if the queue is empty
Element PriorityQueue::top() const {
	//Time complexity O(1)
	if (isEmpty())
		throw exception();
	return elems->info;
}

Element PriorityQueue::pop() {
	//Time complexity O(1)
	if (isEmpty())
		throw exception();
	Element e = elems->info;
	Node *aux = elems->next;
	delete elems;
	elems = aux;
	size--;
	return e;
}

bool PriorityQueue::isEmpty() const {
	//Time complexity O(1)
	if (size == 0)
		return true;
	return false;
}


PriorityQueue::~PriorityQueue() {
	//Time complexity O(n)
	while (elems != NULL) {
		Node *aux = elems->next;
		delete elems;
		elems = aux;
	}
};

