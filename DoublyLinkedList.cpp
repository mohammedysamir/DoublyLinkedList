#include "DoublyLinkedList.h"
#include <cstddef>
template<typename T>
void DoublyLinkedList<T>::insertfirst(T element) {
	Node<T>* newnode=new Node<T>;
	newnode->item = element;
	if (length == 0) {
		first = last = newnode;
		newnode->pre = NULL;
		newnode->point = NULL;
	}
	else {
		newnode->point = first;
		newnode->pre = NULL;
		first->pre = newnode;
		first = newnode;
	}
	length++;
}
template<typename T>
void DoublyLinkedList<T>::print() {
	Node<T>* current = first;
	while (current != NULL) {
		cout << current->item << " ";
		current = current->point;
	}
	cout << endl;
}
template<typename T>
void DoublyLinkedList<T>::insertlast(T element) {
	Node<T>* newnode = new Node<T>;
	newnode->item = element;
	if (length == 0) {
		first = last = newnode;
		newnode->pre = NULL;
		newnode->point = NULL;
	}
	else {
		last->point = newnode;
		newnode->pre = last;
		newnode->point = NULL;
		last = newnode;
	}
	length++;
}
template<typename T>
void DoublyLinkedList<T>::insertAt(int pos, T element) {
	Node<T>* newnode = new Node<T>;
	newnode->item = element;
	if (pos<0 || pos>length)
		cout << "out of range" << endl;
	if (pos == 0)
		insertfirst(element);
	else if (pos == length)
		insertlast(element);
	else {
		Node<T>* current=first;
		for (int i = 1; i < pos; i++)
			current = current->point;
		newnode->point = current->point;
		newnode->pre = current;
		current->point = newnode;
		current->point->pre = newnode;
	}
	length++;
}
template<typename T>
void DoublyLinkedList<T>::removefirst() {
	if (length == 0)
		cout << "empty list can't remove" << endl;
	else if (length == 1) {
		delete first;
		first = last = NULL;
	}
	else {
		
		Node<T>* curr;
		curr = first;
		first = first->point;
		first->pre = NULL;
		delete curr;
		
	}
	length--;
}
template<typename T>
void DoublyLinkedList<T>::removelast(){
	if (length == 0)
		cout << "empty string can't remove" << endl;
	else if (length == 1) {
		delete first;
		length--;
		first = last = NULL;
	}
	else {

		Node<T>* curr = last;
		last = last->pre;
		last->point = NULL;
		delete curr;
		length--;
	}
	
}
template<typename T>
void DoublyLinkedList<T>::remove(T element) {
	if (length == 0)
		cout << "empty string can't remove" << endl;
	else if (first->item == element)
		removefirst();
	else if (last->item == element)
		removelast();
	else {
		Node<T>* curr = first;
		while (curr != NULL) {
			if (curr->item == element)
				break;
			curr = curr->point;
		}
		if (curr == NULL)
			cout << "not found" << endl;
		else {
			curr->pre->point = curr->point;
			curr->point->pre = curr->pre;
			delete curr;
			length--;
		}
	}
}
template<typename T>
void DoublyLinkedList<T>::reverse() {
	Node<T>* front = first;
		Node<T>* end = last;
	while (front != end) {
		swap(front->item, end->item);
		front = front->point;
		end = end->pre;
	}
}
template<typename T>
int DoublyLinkedList<T>::search(T element) {
	Node<T>* current = first;
	int pos = 0;
	while (current != NULL) {
		if (current->item == element)
			return pos;
		current = current->point;
		pos++;
	}
	return -1;
}

