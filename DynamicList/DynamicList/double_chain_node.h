#pragma once

template<typename type>
struct double_chain_node
{
	double_chain_node* prev = nullptr;
	type data;
	double_chain_node* next = nullptr;
};


template<typename type> double_chain_node<type>* addNode(double_chain_node<type> *&LastNodeInList, type data)
{
	double_chain_node<type>* newNode = double_chain_node<type>();
	newNode->data = data;
	if (LastNodeInList == nullptr)
	{
		LastNodeInList = newNode;
		return LastNodeInList;
	}
	else{
		newNode->prev = LastNodeInList;
		return newNode;
	}
}

