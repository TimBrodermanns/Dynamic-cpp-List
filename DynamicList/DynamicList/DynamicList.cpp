#include <iostream>
#include "List.h"
#include "Queue.h"

using namespace std;
using namespace stdList;

int main()
{
	Queue<int> qu;
	for (int i = 0; i < 10; i++)
		qu.queue(i);

	while(!qu.empty())
	{
		cout << qu.dequeu() << endl;
	}
	
	
}

