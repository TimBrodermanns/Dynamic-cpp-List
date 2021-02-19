#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
void addToList(Node<T>*& anchor, T value)
{
    Node<T>* newValue = new Node<T>;
    newValue->data = value; newValue->next = nullptr;
    if (anchor == nullptr)
        anchor = newValue;
    else
    {
        Node<T>* ptr = anchor;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = newValue;
    }
}

template <typename T>
void printList(Node<T>* anchor) {
    cout << "[ ";
    if (anchor != nullptr)
    {
        Node<T>* ptr = anchor;
        do
        {
            cout << ptr->data;
            if (ptr->next != nullptr) cout << " , ";
            else cout << " ";
            ptr = ptr->next;
        } while (ptr != nullptr);
    }
    cout << "]" << endl;
}

