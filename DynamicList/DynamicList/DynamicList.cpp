#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> Mylist;
	Mylist.add(1);
	for (int i = 2; i <= 10; i++)
		Mylist.add(i);
	Mylist.print();
	for(int i = 0; i <10; i++)
	{
		cout << Mylist.at(i);
	}
	cout << endl;

	cout << Mylist[5] << endl;
	
}
