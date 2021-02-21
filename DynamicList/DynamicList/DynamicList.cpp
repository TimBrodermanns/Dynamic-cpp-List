#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> Mylist;
	cout << "Type of list is: " << Mylist.getTypeOfList() << endl;

	Mylist.print();

	for (int i = 1; i <= 10; i++)
		Mylist.add(i);
	Mylist.print();
	
	cout << "length of list is: " << Mylist.length() << endl;
	
	for(int i = 1; i <= 10; i++)
		Mylist.replace(i, i * 100);
	Mylist.print();
	
	int* ary = Mylist.toArray();
	for (int i = 0; i < Mylist.length(); i++)
	{
		cout << ary[i] << " ";
	}
	cout << endl;
	
	Mylist.clear(); //  --> Still buggy <--
	Mylist.print();


}


void ListsInList(){
	List<List<string>>MyListList;
	List<string> List1;
	List<string> List2;
	List<string> List3;

	List1.add("Hello");
	List1.add("World");

	List2.add("Hello");
	List2.add("World");

	List3.add("Hello");
	List3.add("World");

	MyListList.add(List1);
	MyListList.add(List2);
	MyListList.add(List3);

	cout << MyListList[0][0] << " " << MyListList[0][1] << endl;
	cout << MyListList[1][0] << " " << MyListList[1][1] << endl;
	cout << MyListList[1][0] << " " << MyListList[2][1] << endl;
}
