#include "Node.h"

template <typename T>
void hinten_anfuegen(Node<T>*& anker, T wert)
{
    Node<T>* neuer_eintrag = new Node<T>;
    neuer_eintrag->data = wert; neuer_eintrag->next = nullptr;
    if (anker == nullptr)
        anker = neuer_eintrag;
    else
    {
        Node<T>* ptr = anker;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = neuer_eintrag;
    }
}

template <typename T>
void printList(Node<T>* anker) {
    cout << "[ ";
    if (anker != nullptr)
    {
        Node<T>* ptr = anker;
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
