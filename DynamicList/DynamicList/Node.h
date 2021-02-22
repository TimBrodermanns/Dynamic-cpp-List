#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
void addToList(Node<T>*& anchor, T value){
    Node<T>* newValue = new Node<T>;
    newValue->data = value; newValue->next = nullptr;
    if (anchor == nullptr)
        anchor = newValue;
    else{
        Node<T>* ptr = anchor;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = newValue;
    }
}

template <typename T>
void printList(Node<T>* anchor) {
    cout << "[ ";
    if (anchor != nullptr){
        Node<T>* ptr = anchor;
        do{
            cout << ptr->data;
            if (ptr->next != nullptr) cout << " , ";
            else cout << " ";
            ptr = ptr->next;
        } while (ptr != nullptr);
    }
    cout << "]" << endl;
}

template<typename T> unsigned int getLengthOfList(Node<T> *anchor){
    if (anchor == nullptr) return 0;
    Node<T>* ptr = anchor;
    unsigned int counter = 0;
	do{
        counter++;
        ptr = ptr->next;
    } while (ptr != nullptr);
    return counter;
}

template<typename T> Node<T>* deepCopy(Node<T> * orig){
    if (orig == nullptr) {
        return nullptr;
    }
    Node<T>* newAnker = new Node<T>;
    newAnker->data = orig->data;
    while (orig->next != nullptr) {
        orig = orig->next;
        addToList(newAnker, orig->data);
    }
    return newAnker;
}

template<typename T> void deleteList(Node<T> *&anchor){
    if (anchor == nullptr) return;
    Node<T>* ptr = anchor->next;
	do{
        Node<T>* tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    } while (ptr != nullptr);
    delete anchor;
    anchor = nullptr;
}

template<typename T> T getValueAt(Node<T> *anchor, int pos){
    unsigned int counter = 0;
    Node<T> *ptr = anchor;
	do{
		if(counter == pos) return ptr->data;
        counter++;
        ptr = ptr->next;		
    } while (ptr != nullptr);
}

template<typename T> bool replaceInList(Node<T> *anchor, T newValue, int pos){
    if (pos >= getLengthOfList(anchor)) return false;
    unsigned int count = 0;
    Node<T> *ptr = anchor;
	do{
        if (pos == count){
            ptr->data = newValue;
            return true;
        }
        count++;
        ptr = ptr->next;
    } while (ptr != nullptr);
    return false;
}

template<typename T> string ListToString(Node<T> anchor)
{
    string ret = "[ ";
    if (anchor != nullptr) {
        Node<T>* ptr = anchor;
        do {
            ret += ptr->data;
            if (ptr->next != nullptr) ret += " , ";
            else ret += " ";
            ptr = ptr->next;
        } while (ptr != nullptr);
    }
    ret+= "]";
    return ret;
}
