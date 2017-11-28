#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
template <class T>
struct Node {
public:
	T info;
	Node<T> *next;
	Node<T> *prev;
	Node();
	Node(T data) : info(data) {
		next = NULL;
		prev = NULL;
	}
};

template <class T>
class LinkedList {

public:

	std::string name;
	std::string getname();
	Node<T> *head;
	Node<T> *tail;
	int count = 0;
	void insertion(T a);
	LinkedList();
	void destroylist();
	void putwordsintolist(std::string filename);
	void overwriteLL(LinkedList<T> &otherlist);
	void display();
	void writetofile(std::string filename);
	void copylist(LinkedList<T> &otherlist);
	LinkedList<T>& operator=(LinkedList<T> &otherlist);
	bool find(string item);
};




template<class T>
inline Node<T>::Node()
{
	next = NULL;
	prev = NULL;

}

template <class T>
void LinkedList<T>::insertion(T item) {
	Node<T> *temp = new Node<T>(item);

	if (tail == NULL) {
		temp->next = tail;
		temp->prev = head;

		head = temp;
		tail = temp;
	}
	else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}


	//gets the number of bytes
	count++;
}

template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class T>
void LinkedList<T>::display() {
	Node<T> *current;
	current = head;
	while (current != NULL) {
		//cout << current->info.name << endl;
		//cout << current->info.name << endl;
		cout << current->info << endl;
		current = current->next;
	}
}

template<class T>
inline bool LinkedList<T>::find(string item)
{
	bool found = false;
	Node<T> *temp = head;
	while (temp != NULL) {
		if (temp->info == item) {
			found = true;
		}
		temp = temp->next;
	}
	return found;
}
