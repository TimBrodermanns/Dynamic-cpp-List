#pragma once

#include "Node.h"
#include <string>

template<typename T>
class List
{
private:
	Node<T>* anchor = nullptr;
public:
	T at(int pos);
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

template<typename T> T List<T>::at(int pos)
{
	return getValueAt(this->anchor, pos);
}

template<typename T> int List<T>::add(T Value)
{
	addToList(this->anchor, Value);
	return 1;
}
template<typename T> unsigned int List<T>::length()
{
	return getLengthOfList(this->anchor);
}
template<typename T> int List<T>::replace(int pos, T newValue)
{
	return replaceInList(this->anchor, newValue, pos);
}
template<typename T> int List<T>::clear()
{
	deleteList(this->anchor);
	return 1;
}
template<typename T> string List<T>::getTypeOfList()
{
	std::string ret = "";
	for(int i = 0; i < this->length(); i++)
	{
		ret += this->at(i);
	}
	return ret;
}

//parsing
template<typename T> T* List<T>::toArray()
{
	T* ret = new T(getLengthOfList(this->anchor));
	for(int i = 0; i < this->length(); i++)
	{
		ret[i] = this->at(i);
	}
	return ret; 
	
}
template<typename T> void List<T>::print()
{
	printList(this->anchor);
}

//operations
template<typename T> List<T> List<T>::operator[](int pos)
{
	return getValueAt(this->anchor, pos);
}
template<typename T> List<T> List<T>::operator+(T Value)
{
	return NULL;
}
template<typename T> List<T> List<T>::operator=(T Value)
{
	return NULL;
}

