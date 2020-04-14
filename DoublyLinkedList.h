#pragma once
#include<iostream>
using namespace std;
/*
	modification:
	1. insert(value, iterator pos),remove(iterator pos)
	2. iterator interface :	
			-operator++;	//node->point;
			-operator--;	//node->pre;
			-operator*() dereference return item in node		//node->item
			-operator==(const iterator pos) return true if it's pointing to same position
	3.operator =()
			*/
template<typename T>
class DoublyLinkedList
{
	template<typename T>
	struct Node {
		T item;
		Node<T>* point;
		Node<T>* pre;
	};
	
	Node<T>* first;
	Node<T>* last;
	int length=0;
public:
	class iterator {
		Node<T>* iter;
	public:
		iterator() {
			iter = NULL;
		}
		iterator(DoublyLinkedList<T>& l) {
			iter = l.begin();
		}
		void operator++() {
			iter = iter->point;
		}
		void operator--() {
			iter = iter->pre;
		}
		T& operator*() {
			return iter->item;
		}
		
	};
	void insertfirst(T element);
	void insertlast(T element);
	void insertAt(int pos,T element);
	void removefirst();
	void removelast();
	void remove(T element);
	void reverse();
	int search(T element);
	void print();
	Node<T>* begin() { return first; };
	Node<T>* end() { return last; };
	DoublyLinkedList<T>& operator=(DoublyLinkedList<T>& anotherlist) {
		Node<T>* curr = this->first;
		int i = 0;
		while (curr != NULL) {
			cout << "*" << endl;
			anotherlist.insertAt(i,curr->item);
			i++;
			curr = curr->point;
		}
		return *this;
	}
};

