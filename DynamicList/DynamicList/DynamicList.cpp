#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> Mylist;
	Mylist.print();
	for (int i = 1; i <= 10; i++)
		Mylist.add(i);
	Mylist.print();
	for(int i = 1; i <= 10; i++)
		Mylist.replace(i, i * 100);
	Mylist.print();
	Mylist.clear(); //  --> Still buggy <--
	Mylist.print();
}
