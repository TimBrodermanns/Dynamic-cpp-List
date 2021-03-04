#pragma once

#include "double_chain_node.h"

template<typename type>
class performanceList
{
private:
	double_chain_node<type>* anchor;
	double_chain_node<type>* LastInList;
	unsigned int lengthofList = 0;
public:
	void performanceList<type>::add(type _data);
	
};


template<typename type> void performanceList<type>::add(type _data)
{
	if(anchor == nullptr)
	{
		LastInList = addNode(this->anchor);
	}
	else
	{
		LastInList = addNode(this->LastInList);
	}
	lengthofList++;
	return;
}

