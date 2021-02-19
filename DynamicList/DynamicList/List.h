#pragma once

#include "Node.h"
#include <string>

template<typename T>
class List
{
private:
	Node<T>* anchor = nullptr;
public:
	int add(T Value);
	unsigned int length();
	int replace(int pos, T newValue);
	int clear();
	string getTypeOfList();

	//parsing
	T* toArray();
	void print();

	//operations
	List<T> operator[](int pos);
	List<T> operator+(T Value);
	List<T> operator=(T Value);
	//bool operator== (List<T> otherList);
	//bool operator!= (List<T> otherlist);

};

/*
 * !! gets added to .cpp later, causes bugs if in cpp !!
 */

template<typename T> int List<T>::add(T Value)
{
	addToList(this->anchor, Value);
	return 1;
}
template<typename T> unsigned int List<T>::length()
{
	return NULL;
}
template<typename T> int List<T>::replace(int pos, T newValue)
{
	return NULL;
}
template<typename T> int List<T>::clear()
{
	return NULL;
}
template<typename T> string List<T>::getTypeOfList()
{
	return NULL;
}

//parsing
template<typename T> T* List<T>::toArray()
{
	return NULL;
}
template<typename T> void List<T>::print()
{
	printList(this->anchor);
}

//operations
template<typename T> List<T> List<T>::operator[](int pos)
{
	return NULL;
}
template<typename T> List<T> List<T>::operator+(T Value)
{
	return NULL;
}
template<typename T> List<T> List<T>::operator=(T Value)
{
	return NULL;
}

