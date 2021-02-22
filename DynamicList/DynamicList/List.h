#pragma once
#include "Node.h"
#include <string>

namespace stdList{
	template<typename T>
	class List
	{
	private:
		Node<T>* anchor = nullptr;
	public:

		List(){}
		
		List(const List& s) {
			this->anchor = deepCopy(s.anchor);
		}

		~List() {
			deleteList(this->anchor);
		}
		
		T at(int pos);
		int add(T Value);
		unsigned int length();
		int replace(int pos, T newValue);
		int clear();
		string getTypeOfList();
		bool compare(List<T> *&other);
		

		//parsing
		T* toArray();
		void print();
		string toString();

		//operations
		List<T>& operator = (const List<T>& orig);
		List<T> operator+(char c);
		T operator[](int pos);

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
		string ret = typeid(T).name();
		return ret;
	}

	//parsing

	template <typename T>
	string List<T>::toString()
	{
	}


	template<typename T> T* List<T>::toArray()
	{
		T* ret = new T(getLengthOfList(this->anchor));
		for(int i = 0; i < this->length(); i++)
			ret[i] = this->at(i);
		return ret; 
	}
	template<typename T> void List<T>::print()
	{
		printList(this->anchor);
	}

	//operations
	template<typename T> T List<T>::operator[](int pos)
	{
		return getValueAt(this->anchor, pos);
	}

	template <typename T> bool List<T>::compare(List<T> *&other)
	{
		if (this->length() == other->length())
		{
			for (int i = 0; i < this->length(); i++)
			{
				if (this->at(i) != other->at(i))
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		} 
		return true;
	}


	template <typename T> List<T>& List<T>::operator = (const List<T>& orig)
	{
		deleteList(this->anchor);
		this->anchor = deepCopy(orig.anchor);
		return *this;
	}

	template <typename T> List<T> List<T>::operator+(char c) {
		List<T> ret = List<T>(*this);
		this->add(c);
		return ret;
	}

	
}

