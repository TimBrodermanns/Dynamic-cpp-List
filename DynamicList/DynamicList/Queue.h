#pragma once

#include "List.h"

using namespace stdList;
template<typename T>
class Queue
{
private:
	List<T> Queuelist;
public:
	void queue(T value);
	T dequeu();
	unsigned int length();
	bool empty();
};


template<typename T>
void Queue<T>::queue(T value)
{
	this->Queuelist.add(value);
}
template<typename T>
T Queue<T>::dequeu()
{
	T ret = this->Queuelist.at(this->Queuelist.length() - 1);
	this->Queuelist.deleteAt(this->Queuelist.length() - 1);
	return ret;
}
template<typename T>
unsigned int  Queue<T>::length()
{
	return this->Queuelist.length();
}

template<typename T> bool Queue<T>::empty()
{
	if (this->Queuelist.length() == 0) return true;
	return (this->Queuelist.length() < 0) ? true : false;
}
