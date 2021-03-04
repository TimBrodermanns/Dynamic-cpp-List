#pragma once

#include <iostream>

using namespace std;


template <typename T>
struct list_node {
	T data;
	list_node<T>* next = nullptr;
};

template <typename T>
void addToList(list_node<T>*& anchor, T value) {
	list_node<T>* newValue = new list_node<T>;
	newValue->data = value; newValue->next = nullptr;
	if (anchor == nullptr)
		anchor = newValue;
	else {
		list_node<T>* ptr = anchor;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = newValue;
	}
}

template <typename T>
void printList(list_node<T>* anchor) {
	cout << "[ ";
	if (anchor != nullptr) {
		list_node<T>* ptr = anchor;
		do {
			cout << ptr->data;
			if (ptr->next != nullptr) cout << " , ";
			else cout << " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
	}
	cout << "]" << endl;
}

template<typename T> unsigned int getLengthOfList(list_node<T>* anchor) {
	if (anchor == nullptr) return 0;
	list_node<T>* ptr = anchor;
	unsigned int counter = 0;
	do {
		counter++;
		ptr = ptr->next;
	} while (ptr != nullptr);
	return counter;
}

template<typename T> list_node<T>* deepCopy(list_node<T>* orig) {
	if (orig == nullptr) {
		return nullptr;
	}
	list_node<T>* newAnker = new list_node<T>;
	newAnker->data = orig->data;
	while (orig->next != nullptr) {
		orig = orig->next;
		addToList(newAnker, orig->data);
	}
	return newAnker;
}

template<typename T> void deleteList(list_node<T>*& anchor) {
	if (anchor == nullptr) return;
	list_node<T>* ptr = anchor->next;
	do {
		list_node<T>* tmp = ptr->next;
		delete ptr;
		ptr = tmp;
	} while (ptr != nullptr);
	delete anchor;
	anchor = nullptr;
}

template<typename T> T getValueAt(list_node<T>* anchor, int pos) {
	unsigned int counter = 0;
	list_node<T>* ptr = anchor;
	do {
		if (counter == pos) return ptr->data;
		counter++;
		ptr = ptr->next;
	} while (ptr != nullptr);
}

template<typename T> bool replaceInList(list_node<T>* anchor, T newValue, int pos) {
	if (pos >= getLengthOfList(anchor)) return false;
	unsigned int count = 0;
	list_node<T>* ptr = anchor;
	do {
		if (pos == count) {
			ptr->data = newValue;
			return true;
		}
		count++;
		ptr = ptr->next;
	} while (ptr != nullptr);
	return false;
}

template<typename T> string ListToString(list_node<T> anchor)
{
	string ret = "[ ";
	if (anchor != nullptr) {
		list_node<T>* ptr = anchor;
		do {
			ret += ptr->data;
			if (ptr->next != nullptr) ret += " , ";
			else ret += " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
	}
	ret += "]";
	return ret;
}

template<typename T> void deleteValueat(list_node<T>* &anchor, int pos)
{
	if (anchor == nullptr)
		return;
	if (pos >= getLengthOfList(anchor))
		return;
	list_node<T>* ptr = anchor;
	unsigned int currentPos = 0;
	do
	{
		if(pos == currentPos && pos == 0)
		{
			list_node<T>* newAnchor = ptr->next;
			anchor = ptr->next;
			delete ptr;
			return;
		}
		else if(currentPos == pos)
		{
			list_node<T>* ptr_next =ptr->next->next;
			list_node<T>* ptr_delete = ptr->next;
			delete ptr_delete;
			ptr->next = ptr_next;
			return;
		}
		currentPos++;
		ptr = ptr->next;
	} while (ptr->next != nullptr);
}

